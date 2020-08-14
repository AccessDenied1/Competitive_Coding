#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int ans = 0;
		ans = n*(m/2) + (m%2)*((n+1)/2);
		cout<<ans<<endl;
	}
}
