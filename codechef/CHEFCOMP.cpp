#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
vector<long> A(100005),B(100005);
vector<int> P(100005),ans(100005, 0);

void dfs(vector<vector<int>>G , int u , vector<bool> vis, vector<bool>& done, int i)
{
	vis[u] = true;
	if(B[u]!=0)
	{
		B[u] = B[u] - min(A[P[i]] , B[u]);
		if(B[u] == 0)
		{
			ans[u] = i+2;
			//cout<<"ans["<<u<<"]"<<ans[u]<<endl;
		}
	}	
	for(int y : G[u])
	{
		if(!vis[y] && !done[y])
			dfs(G , y,vis , done ,i);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d", &n);
		vector<vector<int>>G(n);
		for(int i=1;i<n;i++)
		{
			int u,v;
			//cin>>u>>v;
			scanf("%d", &u);
			scanf("%d", &v);
			u--;v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0;i<n;i++)
			scanf("%d", &P[i]);
		for(int i=0;i<n;i++)
			scanf("%ld", &A[i]);
		for(int i=0;i<n;i++)
			scanf("%ld", &B[i]);
		vector<bool> vis(n,false) , done(n,false);
		//cout<<"yes"<<endl;
		for(int i=0;i<n;i++)
		{
			P[i]--;
			dfs(G , P[i] ,vis , done , i);
			done[P[i]] = true;
		}
		for(int i=0;i<n;i++)
		{
			//cout<<"Bi = "<<B[i]<<endl;
			cout<<ans[i]-1<<" ";
		}
		cout<<endl;
		std::fill(ans.begin(), ans.begin()+n+2, 0);
	}
}
