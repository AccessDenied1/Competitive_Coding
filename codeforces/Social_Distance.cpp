#include<bits/stdc++.h>
using namespace std;

int fun(string s,int k)
{
	int ans = 0;
	for(int i=0;i<s.size()-k;i=i+k+1)
	{
		if(s[i] == '0' && s[i+k]=='0')
		{
			ans++;
		}
	}
	return ans;
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
		int st = s.size();
		int c = 0,al = 0;
		for(int i=0;i<st;i++)
		{
			if(s[i] == '0')
			{
				int x1 = min(i+k,n-1);
				int x2 = max(0,i-k);
				for(int j=x2;j<=x1;j++)
				{
					if(s[j] == '1')
					{
						al = 1;
						break;
					}
				}
				if(al == 0)
				{
					c++;
					s[i] = '1';
					i = i+k;
				}
				al=0;
			}
		}
		cout<<c<<endl;
	}
}
