#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		char c = s[0];
		for(int i = 1;i<n;i++)
		{
			c = min(s[i] , c);
		}
		cout<<c<<endl;
	}
}
