#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int n,k;
	cin>>n>>k;
	unordered_map<int,int> M;
	M[1] = 0;
	for(int i = 1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		M[y] = M[x] +1;
		//cout<<"readed = "<<x<<" "<<y<<endl;
	}
	vector<int> ans;
	for(auto x : M)
	{
		ans.push_back(x.second);
		//cout<<x.second<<endl;
	}
	sort(ans.begin(),ans.end(),greater<int>());
	int sum = 0;
	for(int i=0;i<k;i++)
	{
		sum+=ans[i];
	}
	cout<<sum<<endl;
}
