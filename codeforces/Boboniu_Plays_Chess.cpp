#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int d = n*m;
	int xx = x , yy =y;
	while(y!=m+1)
	{
		cout<<x<<" "<<y<<endl;
		y++;
	}
	y = yy-1;
	while(y!=0)
	{
		cout<<x<<" "<<y<<endl;
		y--;
	}
	x = 1;
	y = 1;
	int c = 1;
	while(x!=n+1)
	{
		cout<<x<<" "<<y<<endl;
		if(c == 0)
			y--;
		else
			y++;
		if(y == 0)
		{
			x++;
			c = 1;
			y = 1;
		}
		else if(y == m+1)
		{
			x++;
			c = 0;
			y = m;
		}
		if(x == xx)
			x++;
	}
}
