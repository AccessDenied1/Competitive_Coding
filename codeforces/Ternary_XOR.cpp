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
		string x;
		cin>>x;
		string a = "" , b = "";
		int i;
		for(i=0;i<n;i++)
		{
			char al = x[i];
			if(a == b)
			{
				if(al == '2')
				{
					a = a+"1";
					b = b+"1";
				}
				else if(al == '1')
				{
					a = a+"1";
					b = b+"0";
				}
				else
				{
					a = a+"0";
					b = b+"0";
				}
			}
			else
			{
				break;
			}
		}
		if(a<b)
		{
			while(i < n)
			{
				a = a+x[i];
				b = b+"0";
				i++;
			}
		}
		else
		{
			while(i < n)
			{
				b = b+x[i];
				a = a+"0";
				i++;
			}
		}
		cout<<a<<endl;
		cout<<b<<endl;
	}
}
