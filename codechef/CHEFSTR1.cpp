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
		long s = 0;
		for(int i=0;i<n-1;i++)
		{
			s += abs(a[i+1] - a[i])-1;
		}
		cout<<s<<endl;
	}
}
