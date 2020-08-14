#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,p;
		cin>>s>>p;
		vector<int> a(26,0);
		for(char x : s)
			a[x-'a']++;
		for(char x : p)
			a[x-'a']--;
		string g = "";
		int eq = 0;
		for(int i=0;i<p.size()-1;i++)
		{
			if(p[i] < p[i+1])
			{
				eq = 1;
				break;
			}
			if(p[i] > p[i+1])
			{
				eq = 0;
				break;
			}
		}
		for(int i=0;i<26;i++)
		{
			int y = a[i];
			while(y--)
			{
				char f = i+'a';
				g = g+f;
			}
		}
		int idx = 0;
		int n = g.size();
		for(int i=n-1;i>-1;i--)
		{
			if(eq)
			{
				if(g[i] <= p[0])
				{
					idx = i;
					break;
				}
			}
			else
			{
				if(g[i] < p[0])
				{
					idx = i;
					break;
				}
			}
		}
		//cout<<idx<<endl;
		string g2 = p+g;
		g = g.substr(0,idx+1)+p+g.substr(idx+1 , n-idx-1);
		
		cout<<min(g,g2)<<endl;
		
	}
}
