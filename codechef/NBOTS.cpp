#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int f,n;
vector<char> dir;
vector<int> pos;
string getmax()
{
	string ff = "";
	int su = 0;
	int L = 0;
	int ll = INT_MIN;
	int R = 0;
	int rl = INT_MIN;
	int U = 0;
	int ul = INT_MIN;
	int D = 0;
	int dl = INT_MIN;
	int idl = 0 , idr = 0, idu = 0 , idd = 0;
	for(int j = 0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[j][i] !=0)
			{
				su += arr[j][i];
				L++;
				if(su > f)
				{
					L--;
					break;
				}
			}
		}
		if(L > ll)
		{
			ll = L;
			idl = j;
			cout<<"L = "<<L<<endl;
		}
		
		L=0;
		su = 0;
	}
	for(int j = n-1;j>-1;j--)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i][j]!=0)
			{
				su += arr[i][j];
				U++;
				if(su > f)
				{
					U--;
					break;
				}
			}
		}
		if(U > ul)
		{
			ul = U;
			idu = j;
			cout<<"U = "<<U<<endl;
		}
		U=0;
		su = 0;
	}
	for(int j = n-1;j>-1;j--)
	{
		for(int i=n-1;i>-1;i--)
		{
			if(arr[i][j]!=0)
			{
				su += arr[i][j];
				D++;
				if(su > f)
				{
					D--;
					break;
				}
			}
		}
		if(D > dl)
		{
			dl = D;
			idd = j;
			cout<<"D = "<<D<<endl;
		}
		D=0;
		su = 0;
	}
	for(int j = 0;j<n;j++)
	{
		for(int i=n-1;i>-1;i--)
		{
			if(arr[j][i] != 0)
			{
				su += arr[i][j];
				R++;
				if(su > f)
				{
					R--;
					break;
				}
			}
		}
		if(R > rl)
		{
			rl = R;
			idr = j;
			cout<<"R = "<<R<<endl;
		}
		R=0;
		su = 0;
	}
	//cout<<"idl = "<<idl<<endl;
	//cout<<"ll = "<<ll<<endl;
	//cout<<"rl = "<<rl<<endl;
	//cout<<"dl = "<<dl<<endl;
	//cout<<"ul = "<<ul<<endl;
	//cout<<"next"<<endl;
	if(ll > rl && ll > rl && ll > dl)
		return "L"+to_string(idl);
	else if(rl > ll && rl > ul && rl > dl)
		return "R"+to_string(idr);
	else if(dl > rl && dl > ul && dl > ll)
		return "D"+to_string(idd);
	else
		return "U"+to_string(idu);
	
}
void pp()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void print(int ans)
{
	cout<<ans<<endl;
	for(int i=0;i<dir.size();i++)
		cout<<dir[i]<<" "<<pos[i]+1<<endl;
}
int check()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(arr[i][j] != 0)
				return 1;
	return 0;
}
int main()
{
	cin>>n>>f;
	arr.resize(n,vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j = 0;j<n;j++)
			cin>>arr[i][j];
	int k;
	cin>>k;
	int su = 0;
	int ans = 0;
	string st = "";
	while(check())
	{
		st = getmax();
		//cout<<"st  "<<st<<endl;
		char mo = st[0];
		int idx = stoi(st.substr(1,st.size()));
		if(mo == 'L')
		{
			//cout<<"yes"<<endl;
			for(int i=0;i<n;i++)
			{
				su+=arr[idx][i];
				if(su <= f)
					arr[idx][i] = 0;
				else
					break;
			}
			if(su!=0)
			{
				dir.push_back('L');
				pos.push_back(idx);
				ans++;
			}
		}
		else if(mo == 'U')
		{
			for(int i=0;i<n;i++)
			{
				su+=arr[i][idx];
				if(su <= f)
					arr[i][idx] = 0;
				else
					break;
			}
			if(su!=0)
			{
				dir.push_back('U');
				pos.push_back(idx);
				ans++;
			}
		}
		else if(mo == 'D')
		{
			for(int i=n-1;i>-1;i--)
			{
				su+=arr[i][idx];
				if(su <= f)
					arr[i][idx] = 0;
				else
					break;
			}
			if(su!=0)
			{
				dir.push_back('D');
				pos.push_back(idx);
				ans++;
			}
		}
		else
		{
			for(int i=n-1;i>-1;i--)
			{
				su+=arr[idx][i];
				if(su <= f)
					arr[idx][i] = 0;
				else
					break;
			}
			if(su!=0)
			{
				dir.push_back('R');
				pos.push_back(idx);
				ans++;
			}
		}
		//ans++;
		//cout<<"pp"<<endl;
		//pp();
		//cout<<endl;
		su = 0;
	}
	print(ans);
	//pp();
}	
