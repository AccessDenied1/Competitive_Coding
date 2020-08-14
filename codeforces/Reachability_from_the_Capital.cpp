#include<bits/stdc++.h>
using namespace std;
int sz = 0;
void DFS(int u , vector<vector<int>> ad , vector<bool> &vis)
{
	vis[u] = true;
	//cout<<u<<" ";
	sz++;
	for(int i=0;i<ad[u].size();i++)
		if(!vis[ad[u][i]])
			DFS(ad[u][i] , ad , vis);
}
/*vector<int> dfs(vector<vector<int>> ad , int n , int s)
{
	vector<bool> vis(n , false);
	vector<int> sz(n , 0);
	for(int u = 0;u<n ; u++)
	{
		if(!vis[u])
			DFS(u , ad , vis , sz);
	}
	DFS(s , ad , vis);
	return sz;
}*/
int main()
{
	int n , m , s;
	cin>>n>>m>>s;
	s--;
	vector<vector<int>> ad(n);
	for(int i=0;i<m;i++)
	{
		int u , v;
		cin>>u>>v;
		u--;
		v--;
		ad[u].push_back(v);
	}
	vector<bool> vis(n , false);
	DFS(s , ad , vis);
	int ans = 0;
	vector<pair<int,int>> vv;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			sz = 0;
			DFS(i , ad , vis);
			
		}
	}
	cout<<ans<<endl;
}
	
	
	
