#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		string s;
		cin>>n>>q>>s;
		vector<int> M(26,0);
		for(char c : s)
		{
			int idx = (int)c - 97;
			M[idx]++;
		}
		while(q--)
		{
			int c;
			cin>>c;
			int ans = 0;
			for(int i : M)
			{
				ans += i-c >=0 ? (i-c) : 0;
			}
			cout<<ans<<endl;
		}
	}
}
