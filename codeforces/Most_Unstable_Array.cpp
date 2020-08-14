#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n,m;
		cin>>n>>m;
		long ans = 0;
		if(n == 1)
		{
			cout<<0<<endl;
		}
		else if( n == 2)
		{
			cout<<m<<endl;
		}
		else if(n == 3)
		{
			cout<<2*m<<endl;
		}
		else
		{
			long h = n/2;
			if(n%2 == 0)
			{
				ans = 2*m;
			}
			else
			{
				ans = 2*m;
			}
			cout<<ans<<endl;
		}
	}
}
