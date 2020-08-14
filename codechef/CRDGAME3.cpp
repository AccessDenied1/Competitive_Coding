#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int s = 0;
		int a = 0,b=0;
		a = x/9 + (x%9!=0);
		b = y/9 + (y%9!=0);
		if(a >= b)
		cout<<1<<" ";
		else
		cout<<0<<" ";
		cout<<min(a,b)<<endl;
	}
}
