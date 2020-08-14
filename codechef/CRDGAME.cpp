#include<bits/stdc++.h>
using namespace std;
int sum(long x)
{
	int s = 0;
	while(x!=0)
	{
		s += x%10;
		x /=10;
	}
	return s;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int c = 0,m = 0;
		for(int i=0;i<n;i++)
		{
			long x1,x2;
			cin>>x1>>x2;
			int s1 = sum(x1);
			int s2 = sum(x2);
			if(s1>s2)
			{
				c++;
			}
			else if(s1<s2)
			{
				m++;
			}
			else
			{
				c++;
				m++;
			}
		}
		if(c>m)
		{
			cout<<0<<" "<<c<<endl;
		}
		else if(c<m)
		{
			cout<<1<<" "<<m<<endl;
		}
		else
		{
			cout<<2<<" "<<c<<endl;
		}
	}
}
