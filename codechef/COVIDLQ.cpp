#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int p[n];
		for(int i=0;i<n;i++)
			cin>>p[i];
		int st = 0,x=0;
		for(int i=0;i<n;i++)
		{
			if(p[i] == 1)
			{
				st = i;
				break;
			}
		}
		int c=0;
		for(int i = st+1 ;i<n;i++)
		{
			if(p[i] == 0)
			{
				x++;
			}
			else
			{
				if(x<5)
				{
					//cout<<"for = "<<x<<endl;
					cout<<"NO"<<endl;
					c=1;
					break;
				}
				else
				{
					//cout<<"yes at i = "<<i<<endl;
					x = 0;
				}
			}
		}
		if(c==0)
			cout<<"YES"<<endl;
	}
}

