#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long a[3];
		cin>>a[0]>>a[1]>>a[2];
		long ans;
		ans = a[0]+a[1]+a[2];
		cout<<ans/2<<endl;
	}
}
