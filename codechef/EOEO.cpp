#include<bits/stdc++.h>
using namespace std;

int solve(int t , int j)
{
	if(t%2 == 0 && j%2==0)
		return solve(t/2 , j/2);
	else if(t%2 == 0 && j%2==1)
		return 0;
	else if(t%2 == 1 && j%2==0)
		return 1;
	else
		return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long ts;
		cin>>ts;
		if(ts%2)
		{
			cout<<(ts/2)<<endl;
		}
		else
		{
			long long x = (ts&(~(ts-1)))*2;
			cout<<(ts/x)<<endl;
		}
	}
}
	
		
