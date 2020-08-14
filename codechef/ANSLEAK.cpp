#include<iostream>
using namespace std;
#include<vector>
vector<int> max_index(vector<int> ma)
{
	int mm = ma[0];
	vector<int> idx;
	for(int i=1;i<ma.size();i++)
		mm = max(mm,ma[i]);
	for(int i=0;i<ma.size();i++)
	{
		if(ma[i] == mm)
		{
			idx.push_back(i);
		}
	}
	return idx;
}
void print(vector<int> v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
int check(vector<int> a , int x)
{
	int c =0;
	for(int i = 0;i<a.size();i++)
	{
		if(a[i] == x)
			c++;
	}
	return c;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		vector<vector<int>> a(n,vector<int> (k));
		vector<int> ma(m+1 , 0);
		vector<int> zero(m+1,0);
		for(int i=0;i<n;i++)
			for(int j = 0;j<k;j++)
				cin>>a[i][j];
		vector<vector<int>> idx_lt;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<k;j++)
			{
				ma[a[i][j]]++;
			}

			vector<int> mz = max_index(ma);
			idx_lt.push_back(mz);
			ma = zero;
		}
		int ans[n];
		int c = 0;
		for(int i=0;i<n;i++)
		{
			int x = idx_lt[i].size();
			for(int j=0;j<x;j++)
			{
				int al  = idx_lt[i][j];
				int x = check(a[i] , al);
				if(x>c)
				{
					ans[i] = al;
					c = x;
				}
			}
			c = 0;
		}
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		/*for(int i=0;i<idx_lt.size();i++)
		{
			for (int j = 0; j < idx_lt[i].size(); ++i)
			{
				//check(idx_lt[i][j])
			}
		}
		cout<<endl;*/
	}
}