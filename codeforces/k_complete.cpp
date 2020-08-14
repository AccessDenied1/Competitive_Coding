#include<iostream>
using namespace std;
#include<vector>
char arg(vector<int> ch)
{
	int m = 0,idx = 0;
	for(int i = 0;i<26;i++)
	{
		if(ch[i] > m)
		{
			m = ch[i];
			idx = i;
		}
	}
	return idx + 97;
}
void print(vector<int> ch)
{
	for(int i=0;i<26;i++)
	{
		cout<<ch[i]<<endl;
	}
	cout<<"done"<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<string> str;
		int i = 0;
		int ans = 0;
		while(i<n)
		{
			str.push_back(s.substr(i,k));
			i = i+k;
		}
		/*for(int i=0;i<str.size();i++)
		{
			cout<<str[i]<<endl;
		}*/
		vector<int> ch(26,0);
		int idx;
		for(int j=0;j<=k/2;j++)
		{
			fill(ch.begin(),ch.end(),0);
			for(i=0;i<str.size();i++)
			{
				idx = int(str[i][j]) - 97;
				ch[idx]++;
				idx = int(str[i][k-j-1]) - 97;
				ch[idx]++;
			}
			//print(ch);
			char x = arg(ch);
			for(i=0;i<str.size();i++)
			{
				if(x!=str[i][j])
				{
					str[i][j] = x;
					ans++;
				}
				if(x!=str[i][k-j-1])
				{
					str[i][k-j-1] = x;
					ans++;
				}
			}
			
		}
		//cout<<"new"<<endl;
		/*for(int i=0;i<str.size();i++)
		{
			cout<<str[i]<<endl;
		}*/
		cout<<ans<<endl;
	}
}	
