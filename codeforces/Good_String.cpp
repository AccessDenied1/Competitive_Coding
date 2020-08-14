#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i=0;
	int d = 0;
	while(i<s.size()-1)
	{		
		if(s[i] == s[i+1])
		{
			s.erase(i,1);
			d++;
		}
		else
			i = i+2;
	}
	if(s.size()%2)
	{
		d++;
		s = s.substr(0 , s.size()-1);
	}
	cout<<d<<endl;
	cout<<s<<endl;
}
