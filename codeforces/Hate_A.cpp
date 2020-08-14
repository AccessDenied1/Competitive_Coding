#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.size();
	string s2 = s;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i] == 'a')
		{
			s2.erase(i,1);
			i--;
		}	
	}
	int n2 = s2.size();
	//cout<<"n2 = "<<n2<<endl;
	//cout<<s2<<endl;
	if(n2%2)
		cout<<":("<<endl;
	else if(n2 == 0)
		cout<<s<<endl;
	else
	{
		int n3 = n2/2;
		string y = s2.substr(0,n3);
		string y2 = s2.substr(n3 , n2);
		if(y!=y2)
			cout<<":("<<endl;
		else
		{
			string sf = s.substr(0,n-n3);
			for(int i=0;i<sf.size();i++)
			{
				if(sf[i] == 'a')
				{
					sf.erase(i,1);
					i--;
				}	
			}
			if(sf != y)
				cout<<":("<<endl;
			else
				cout<<s.substr(0,n-n3)<<endl;
		}
			
	}
}
