#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		long long ans = 0;
		long h = n/2;
		while(n>0)
		{
			long long out = n + 2*(n-1) + n-2;
			ans += 1LL * h*out;
			n = n-2;
			h--;
		}
		cout<<ans<<endl;
	}
}
