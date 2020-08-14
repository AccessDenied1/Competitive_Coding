#include<bits/stdc++.h>
using namespace std;

int solve_for(int i, int a[] , int n)
{
	int c = 0;
	for(int j = i;j<n-1;j++)
	{
		if(a[j+1] - a[j] <= 2)
			c++;
		else
			break;
	}
	return c;
}
int solve_back(int i, int a[])
{
	int c = 0;
	for(int j = i;j>0;j--)
	{
		if(a[j]-a[j-1] <= 2)
			c++;
		else
			break;
	}
	return c;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++)
			cin>>a[i];
		int ma = 0, mi = n;
		for(int i = 0;i<n;i++)
		{
			int x = solve_for(i,a,n)+solve_back(i,a);
			ma = max(x,ma);
			mi = min(x,mi);
		}
		cout<<mi+1<<" "<<ma+1<<endl;
	}
}
