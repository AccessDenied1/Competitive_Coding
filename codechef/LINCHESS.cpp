#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long k;
		cin>>n>>k;
		long m = 10e9+1;
		long ans = -1;
		long x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(k%x == 0)
			{
				if(m > k/x)
				{
					m = k/x;
					ans = x;
				}
			}
		}
		cout<<ans<<endl;
	}
}
