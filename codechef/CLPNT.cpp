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
		long q;
		cin>>q;
		sort(a,a+n);
		while(q--)
		{
			long x,y;
			cin>>x>>y;
			long s = x+y;
			int al = 0;
			long ans = n;
			int l = 0,r = n-1;
			while(l<=r)
			{
				int m = l + (r-l)/2;
				if(a[m] > s)
				{
					ans = m;
					r = m-1;
				}
				else if(a[m] < s)
					l = m+1;
				else
				{
					al = 1;
					break;
				}
			}
			if(al)
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
		}
	}
}
