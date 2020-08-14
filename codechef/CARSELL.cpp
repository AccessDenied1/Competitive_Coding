#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long p[n];
		for(int i=0;i<n;i++)
			cin>>p[i];
		long mod = 1e9+7;
		long s2 = 0;
		sort(p,p+n);
		for(int i=0;i<n;i++)
		{
			int a = p[i]-n+1+i;
			int b = max(0,a);
			s2 = ((s2%mod) + (b%mod))%mod;
			
		}
		cout<<s2<<endl;
	}
}
