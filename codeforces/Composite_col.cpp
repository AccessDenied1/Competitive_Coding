#include<iostream>
using namespace std;
#include<bits/stdc++.h>

#include<vector>
int gcd(int a,int b)
{
	if(b==0)
		return a;
	gcd(b,a%b);
}
int check (vector<int> v , int x)
{
	for(int i=0;i<v.size();i++)
	{
		int g = gcd(v[i] , x);
		if(g == 1)
			return 0;
	}
	return 1;
}
void print(vector<int> v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
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
		vector<int> col;
		set<int> s1;
		map<int , vector<int>> umap;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		vector<int> v;
		v.push_back(a[0]);
		umap[1] = v;
		int m=1;
		col.push_back(m);
		int op;
		int ma_sz = 0;
		int ma_sz_idx = 0;
		for(int i=1;i<n;i++)
		{
			op = 0;
			ma_sz = 0;
			ma_sz_idx = 0;
			for(int j = 1;j<=m;j++)
			{
				vector<int> temp = umap[j];
				int al = check(temp , a[i]);
				if(al == 1)
				{
					if(umap[j].size() > ma_sz)
					{
						ma_sz = umap[j].size();
						ma_sz_idx = j;
					}
				}
			}
			if(ma_sz != 0)
			{
				umap[ma_sz_idx].push_back(a[i]);
				col.push_back(ma_sz_idx);
			}
			else
			{
				vector<int> vv;
				vv.push_back(a[i]);
				umap[m+1] = vv;
				col.push_back(m+1);
				m++;
			}
		}
		cout<<m<<endl;
		for(int i=1;i<=m;i++)
		{
			print(umap[i]);
			
		}
		for(int i=0;i<col.size();i++)
		{
			cout<<col[i]<<" ";
		}
		cout<<endl;
	}
}
			
