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
		long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int w = 1 , i=0;
		int f = -1;
		for(i=0;i<n;i++)
		{
			if(a[i] ==1)
			{
				w = 1-w;
			}
			else
			{
				break;
			}
		}
		
		if(i==0)
			cout<<"First"<<endl;
		else if(i == n)
		{
			if(n%2==0)
				cout<<"Second"<<endl;
			else
				cout<<"First"<<endl;
		}
		else if(w == 1)
			cout<<"First"<<endl;
		else if(w == 0)
			cout<<"Second"<<endl;
		
				
	}
}
