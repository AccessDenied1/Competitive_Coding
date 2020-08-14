#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,d;
	cin>>r>>d;
	int n;
	cin>>n;
	int ans = 0;
	while(n--)
	{
		int x , y , r2;
		cin>>x>>y>>r2;
		double d1 = sqrt(x*x + y*y);
		if(d1+r2 <= r && (d1-r2) >= (r-d))
		{
			//cout<<"yes for "<<x<< " "<<y<<" "<<r2<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
}
