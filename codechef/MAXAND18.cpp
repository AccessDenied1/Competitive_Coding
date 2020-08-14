#include<bits/stdc++.h>
using namespace std;
int set(long long x)
{
	int s = 0;
	while(x)
	{
		s += x&1;
		x = x>>1;
	}
	return s;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<long> a(n);
		long long rr = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			rr = rr | a[i];
		}
	}
}
