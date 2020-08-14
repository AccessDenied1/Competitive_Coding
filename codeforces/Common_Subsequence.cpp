#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1,n2;
		cin>>n1>>n2;
		int a1[n1] , a2[n2];
		for(int i=0;i<n1;i++)
			cin>>a1[i];
		for(int i=0;i<n2;i++)
			cin>>a2[i];
		
		map<int,int> m;
		for(int i=0;i<n1;i++)
		{
			m[a1[i]] = min(1 , m[a1[i]]+1);
		}
		int al = 0;
		for(int x : a2)
		{
			if(m[x] == 1)
			{
				cout<<"YES"<<endl;
				cout<<1<<" "<<x<<endl;
				al = 1;
				break;
			}
		}
		if(al==0)
		cout<<"NO"<<endl;
	}
}
