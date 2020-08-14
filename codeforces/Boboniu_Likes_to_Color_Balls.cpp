#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long r,g,b,w;
		int a[3];
		cin>>a[0]>>a[1]>>a[2]>>w;
		sort(a,a+3);
		r  = a[0];
		g = a[1];
		b = a[2];
		
		int ans = 0 ;
		w = w%2;
		int h = r%2 + g%2 + b%2;
		if(r == 0)
		{
			h = h + w;
			if(h<=1)
			ans = 1;
			else
			ans = 0;
		}
		else if((w%2 && h!=1) ||(!w%2 && h!=2))
		{
				ans = 1;
		}
		else
		{
			ans = 0;
		}
		if(ans)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
