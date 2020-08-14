#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	string s = to_string(t)  , s2 = "";
	int f = 0,f2=0;
	int n = s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i] != '0')
			break;
		f++;
	}
	for(int i=n-1;i>-1;i--)
	{
		if(s[i] != '0')
			break;
		f2++;
	}
	//cout<<f<<endl;
	//cout<<f2<<endl;
	int fin = f2-f;
	//cout<<fin<<endl;
	if(fin < 0)
		cout<<"NO"<<endl;
	else
	{
		string s3 = s.substr(0,n-fin);
		string s4 = s3;
		reverse(s3.begin(),s3.end());
		if(s3==s4)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}		
}
