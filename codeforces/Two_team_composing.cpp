#include<iostream>
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
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		unordered_map<int,int> M;
		M[a[0]] = 1;
		for(int i=1;i<n;i++)
		{
			if(M.find(a[i]) == M.end())
			{
				M[a[i]] = 1;
			}
			else
				++M[a[i]];
		}
		int dis = M.size()-1;
		int s = 1;
		for(auto x : M)
		{
			if(x.second!=1)
			{
				s=max(s,x.second);
			}
		}
		if(s-dis == 2)
			cout<<(dis+1)<<endl;
		else
		{
			int x = dis+1;
			int y = s-1;
			int ans = min(x,y);
			int ans2 = min(s,dis);
			cout<<max(ans,ans2)<<endl;
		}
	}
}
