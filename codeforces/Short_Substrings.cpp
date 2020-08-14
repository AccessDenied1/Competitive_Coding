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
		string ans;
		int n = s.size();
		for(int i=1;i<n;i=i+2)
			ans = ans+s[i];
		cout<<s[0]+ans<<endl;
	}
}
