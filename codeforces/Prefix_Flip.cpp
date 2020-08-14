#include<bits/stdc++.h>
using namespace std;

void flip(string &a , int i)
{
	for(int x = 0;x<=i ;x++)
	{
		a[x] = a[x] == '1'? '0' : '1'; 
	}
	string s = a.substr(0,i+1);
	reverse(s.begin() , s.end());
	for(int x = 0;x<=i ;x++)
	{
		a[x] = s[x];
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int j = n-1;
		vector<int> ans;
		int k = 0;
		while(a!=b && k <= 3*n)
		{
			if(a[j] != b[j])
			{
				int al = 0;
				for(int i = j;i>-1;i--)
				{
					if(a[i] == a[0])
					{
						al = 1;
						flip(a,i);
						k++;
						ans.push_back(i+1);
						break;
					}
				}
				if(al==0)
				{
					flip(a,j);
					k++;
					ans.push_back(j+1);
				}		
			}
			else
			{
				j--;
			}
		}
		cout<<k<<" ";
		for(int x : ans)
			cout<<x<<" ";
		cout<<endl;
		//cout<<a<<endl;
		//cout<<b<<endl;
	}
}
