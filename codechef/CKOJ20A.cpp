#include<bits/stdc++.h>
using namespace std;

int main()
{
	
		int n;
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		long x=-1,y=-1,z=-1;
		for(int i=0;i<n-2;i++)
		{
			if(a[i]+a[i+1] > a[i+2])
			{
				x = a[i];
				y = a[i+1];
				z = a[i+2];
			}
		}
		if(x==-1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<z<<" "<<y<<" "<<x<<endl;
		}
}
