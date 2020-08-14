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
		string s;
		cin>>s;
		int ans = 0;
		map<int,int>mp;
		vector<int> pre(n,0);
		pre[0] = (s[0] - '0');
		int res = 0; 
		if(pre[0] == 1)
			res++;
		for(int i=1;i<n;i++)
		{
			pre[i]  = pre[i-1] + (s[i] - '0');
			if(pre[i] == i+1)
				res++;
			//cout<<pre[i]<<endl;
		}
		for(int i=0;i<n;i++)
		{
			mp[pre[i] - i]++;
		}
    	for (auto x : mp) 
    	{ 
        	int cnt = x.second; 
       		res += cnt*(cnt-1)/2;
        }
		cout<<res<<endl;
	}
}
