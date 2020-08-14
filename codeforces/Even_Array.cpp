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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int e = 0,o=0;
		for(int i=0;i<n;i++)
		{
			if((i%2 == 0 && a[i]%2 == 1))
				o++;
			else if((i%2 == 1 && a[i]%2 == 0))
				e++;
		}
		if(o!=e)
			cout<<-1<<endl;
		else
			cout<<o<<endl;
		
	}
}
