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
		long long a[n];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		if(n == 1)
			cout<<a[0]<<":"<<1<<endl;
		else
		{
			sort(a,a+n);
			int c = 1;
			for(int i=0;i<n-1;i++)
			{
				if(a[i] == a[i+1])
				{
					c++;
				}
				else
				{
					cout<<a[i]<<":"<<c<<endl;
					c = 1;
				}
			}
			if(c!=1)
			{
				cout<<a[n-1]<<":"<<c<<endl;
			}
			else
			{
				cout<<a[n-1]<<":"<<1<<endl;
			}
		}
	}
}
