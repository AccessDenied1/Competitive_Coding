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
		int c = 0,i,j,k;
		if(n%2 && a[n/2] == 1)
			cout<<"NO"<<endl;
		else
		{
			for(i=0;i<=n-3;i++)
			{
				if(a[i+1] > a[i] && a[i+1]>a[i+2])
				{
					j = i+1;
					k = i+2;
					break;
				}
			}
			cout<<"YES"<<endl;
			cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
		}
	}
}
