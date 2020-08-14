#include<bits/stdc++.h>
using namespace std;
long solve(long st , long end,long n)
{
	long mid = st+(end-st)/2;
	char c1,c2,c3,c4;
	cout<<n<<endl;
	cin>>c1;
	if(c1 == 'E')
		return mid;
	cout<<mid<<endl;
	cin>>c2;
	if(c2 == 'E')
		return mid;
	if(c1 == 'L')
	{
		cout<<mid<<endl;
		cin>>c3;
		if(c3 == c2)
		{
			if(c2 == 'L')
				return solve(st , mid-1,n);
			else
				return solve(mid+1 , end,n);
		}
		else
		{
			char x='G',y;
			while(x!='L')
			{
				cout<<mid<<endl;
				cin>>y;
				cout<<1<<endl;
				cin>>x;
			}
			if(y == 'L')
				return solve(st , mid-1,n);
			else
				return solve(mid+1 , end,n);
		}
	}
	else
	{
		if(c2 == 'L')
			return solve(st , mid-1,n);
		else
			return solve(mid+1 , end,n);	
	}
}
int main()
{
	long n;
	cin>>n;
	int x = solve(1,n,n);
	return 0;
}
