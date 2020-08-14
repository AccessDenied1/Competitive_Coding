#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s = "";
		int n,a,b;
		cin>>n>>a>>b;
		int i=0;
		while(i<b)
		{
			s=s+char(i+97);
			i=i+1;
		}
		int x = a-b;
		i=0;
		while(i<x)
		{
			s=s+s[i];
			i=i+1;
		}
		x = n-a;
		i=0;
		while(i<x)
		{
			s=s+s[i];
			i=i+1;
		}
		cout<<s<<endl;
	}
}
