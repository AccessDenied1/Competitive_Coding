#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int> (m,0));
	vector<vector<int>> T(n,vector<int> (m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>T[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//cout<<T[i][j]<<" "<<endl;
		}
	}
	a[0][0] = T[0][0];
	for(int i=1;i<m;i++)
	{
		a[0][i] = a[0][i-1] + T[0][i];
	}
	for(int j=1;j<n;j++)
	{
			a[j][0] = a[j-1][0] + T[j][0];
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			a[i][j] = T[i][j] + max(a[i-1][j] , a[i][j-1]);
		}
	}
	/*for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
	}*/
	for(int i=0;i<n;i++)
	{
		cout<<a[i][m-1]<<" ";
	}
	cout<<endl;
}
