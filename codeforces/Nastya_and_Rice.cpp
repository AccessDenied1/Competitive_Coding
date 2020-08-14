#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int x1 = n*(a-b);
		int x2 = n*(a+b);
		int y1 = c-d;
		int y2 = c+d;
		if(x1 > y2 || x2 < y1)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
}
	
