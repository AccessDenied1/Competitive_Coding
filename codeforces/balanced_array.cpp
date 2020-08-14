#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int k = n/2;
		if(k%2)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			int c = 2;
			for(int i = 1 ; i<=k;i++)
			{
				cout<<c<<" ";
				c=c+2;
			}
			c = 1;
			for(int i = 1 ; i<k;i++)
			{
				cout<<c<<" ";
				c=c+2;
			}
			cout<<3*k-1<<endl;
		}
	}
}
