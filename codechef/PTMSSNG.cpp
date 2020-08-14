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
		long al = (4*n)-1;
		long x,y,X = 0,Y = 0;
		long h = 0;
		while(h<al)
		{
			cin>>x>>y;
			X = X ^ x;
			Y = Y ^ y;
			h++;
		}
		cout<<X<<" "<<Y<<endl;
	}
}
