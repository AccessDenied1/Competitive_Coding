#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,p;
		cin>>h>>p;
		while(h>0 && p>0)
		{
			h = h-p;
			p = p/2;
		}
		if(h<1)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
}
