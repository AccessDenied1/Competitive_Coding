#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n] , b[m];
	vector<int> c(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int ans = 0;
	int y = INT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			y = min(y , ans|(a[i]&b[j]));
		}
		ans = y;
		y = INT_MAX;
	}
	cout<<ans<<endl;
	
}
