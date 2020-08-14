#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		int m = min(x,y);
		int ma = max(x,y);
		long long s,s2,s3;
		s = a*(x+y);
		s2 = b*m + a*(ma-m);
		//s3 = a*(ma-m) + b*m;
		cout<<(min(s,s2))<<endl;
	}
		 
}
