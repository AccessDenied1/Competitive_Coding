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
		int al = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2 == 0)
				al=1;
		}
		if(al == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
