#include <bits/stdc++.h> 
using namespace std;

vector<int> A;
vector<int>mul;
#define MAXN 1000001 
int spf[MAXN];
int mod = 1e9+7;
vector<int> F(MAXN,0);
vector<int> zer(MAXN,0);


void print()
{
	cout<<"print"<<endl;
	for(int i : F)
	{
		if(i!=0)
			cout<<i<<" ";
	}
	cout<<endl;
}
void addEdge(vector<int> v[], int x, int y)
{
	v[x].push_back(y); 
	v[y].push_back(x); 
} 
void printPath(vector<int> stack) 
{ 
	int i; 
	for (i = 0; i < stack.size() - 1; i++) 
	{ 
		mul.push_back(stack[i]-1);
	}
	mul.push_back(stack[i]-1);
}
void DFS(vector<int> v[], bool vis[],int x, int y,vector<int> stack) 
{ 
	stack.push_back(x); 
	if (x == y)
	{ 
		printPath(stack); 
		return; 
	} 
	vis[x] = true; 
	int flag = 0; 
	if (!v[x].empty()) { 
		for (int j = 0; j < v[x].size(); j++)
		{ 
			// if the node is not visited 
			if (vis[v[x][j]] == false) { 
				DFS(v, vis, v[x][j], y, stack); 
				flag = 1; 
			} 
		} 
	} 
	if (flag == 0) { 
		stack.pop_back(); 
	} 
} 
void DFSCall(int x, int y,vector<int> v[], int n, vector<int> stack) 
{ 
	bool vis[n + 1]; 

	memset(vis, false, sizeof(vis)); 
	DFS(v, vis, x, y, stack); 
}
void sieve() 
{
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int fac() 
{
	int c = 1;
	for(int y : mul)
	{
		int x = A[y]; 
    	while (x != 1) 
    	{ 
        	F[spf[x]]++;
        	x = x / spf[x]; 
    	}
	}
	//print();
	for(int i : F)
	{
		if(i!=0)
		{
			c =((c%mod)*((i+1)%mod))%mod;
			//cout<<" i = "<<i<<endl;
		}
	}
	mul.clear();
	F=zer;
	return c;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v[n+1], stack; 
		for(int i=1;i<n;i++)
		{
			int x ,y;
			cin>>x>>y;
			addEdge(v, x, y); 
		}
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			A.push_back(x);
		}

		int q;
		cin>>q;
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			DFSCall(x, y, v, n+1, stack);
			int c= fac();
			cout<<c<<endl;
		}
	}
}