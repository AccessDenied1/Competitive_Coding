#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		stack<char> st;
		int q;
		cin>>q;
		vector<int> a;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == ')' && st.empty())
			{
				continue;
			}
			else
			{
				if(s[i] == '(')
					st.push('(');
				else
				{
					st.pop();
					if(st.empty())
						a.push_back(i);
				}
			}
		}
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i]<<" ";
		}
	}
}
