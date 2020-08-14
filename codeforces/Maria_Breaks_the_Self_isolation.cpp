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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int j = 0;
		int ans = 1;
		for(int i = 0;i<n;i++)
		{
			int x = a[i];
			j++;
			if(x<=j)
			{
				ans=i+2;
			}
		}
		cout<<ans<<endl;
	}
}
