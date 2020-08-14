#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,n,m;
		cin>>x>>n>>m;
		int c = 0;
		while(n>0 && x>20)
		{
			x = (x/2) + 10;
			n--;
		}
		while(m>0)
		{
			x = x - 10;
			m--;
			if(x<1)
			{
				c=1;
				break;
			}
		}
		if(c == 1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
