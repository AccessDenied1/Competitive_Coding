#include<bits/stdc++.h>
using namespace std;
int power(int i)
{
	int res = 1;
	long long x = 2;
	while(y>0)
	{
		if(y&1)
			res = (res*2)%m;
		y = y>>1;
		x = x*x
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
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<long long> ans(n);
		for(int i=0;i<n;i++)
		{
			ans[n-1-i] = pow(2,i);
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[v[i]-1]<<" ";
		}
		cout<<endl;
	}
}
