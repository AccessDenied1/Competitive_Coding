#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 10e9+7;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x1,x2,y1,y2;
		ll a,b,c,d;
		cin>>x1>>x2>>y1>>y2;
		cin>>a>>b>>c>>d;
		
		ll ax1 = a*x1;
		ll ax2 = a*x2;
		ll by1 = b*y1;
		ll by2 = b*y2;
		ll r1 = ax1 + by1;
		ll r2 = ax2 + by2;
		r1 = d - r1;
		r2 = d - r2;
		//cout<<"r1 = "<<r1<<", r2 = "<<r2<<endl;
		ll tot = 0;
		if(r1 % c == 0)
			tot = (r2/c) - (r1/c) + 1;
		else
			tot = (r2/c) - (r1/c);
		tot = tot%mod;
		cout<<tot<<endl;
	}
}
