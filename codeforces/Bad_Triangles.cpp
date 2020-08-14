#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		long x=-1,y,z;
		int c=0;
		for(int i=0;i<n-1;i++)
		{
			if((a[i]+a[i+1] <= a[n-1]))
			{
				x = i;
				y = i+1;
				z = n-1;
				c=1;
				break;
			}
		}
		if(c)
			cout<<x+1<<" "<<y+1<<" "<<z+1<<endl;
		else
			cout<<-1<<endl;
	}
}
