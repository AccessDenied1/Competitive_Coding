#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		map<int,int> m;
		int h = 0;
		for(int i=0;i<n;i++)
			cin>>v[i];
			
		int ans = 1;
		for(int i=0;i<n-1;i++)
		{
			if(v[i] == v[i+1])
			{
				ans++;			
			}
		}
		cout<<ans<<endl;
	}
}
