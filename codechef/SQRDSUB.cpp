#include<iostream>
using namespace std;
long long int odd_mul(int a[] , int n)
{
	long long int odd = 0;
	long long int y = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] ==1)
			++y;
		else
		{
			odd += (y)*(y+1)/2;
			y=0;
		}
	}
	if(y>0)
		odd += y*(y+1)/2;
	return odd;
}
long long int mul_of_four(int a[],int n)
{
	int two = 0,y=0,last=0;
	long long even = 0;
	for( int i=0;i<n;i++)
	{
		if(a[i] == 1)
		{
			++y;
			continue;
		}
		if(a[i] == 2 && two == 0)
		{
			++y;
			last = i;
			two = 1;
			continue;
		}
		if(a[i] == 2 && two == 1)
		{
			even += y*(y+1)/2;
			i = last;
			two = 0;
			y=0;
			continue;
		}
		if(a[i] == 4)
		{
			even += y*(y+1)/2;
			two = 0;
			y=0;
		}
	}
	if(y>0)
		even += y*(y+1)/2;

	//cout<<"even = "<<even<<endl;
	long long sub = 0;
	int c = 0;
	last = 0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] == 2 && c == 0)
		{
			c = 1;
			last = i;
			continue;
		}
		if(a[i] == 2 && c ==1)
		{
			int x = i-last-1;
			sub += x*(x+1)/2;
			c=1;
			last = i;
			continue;
		}
		if(a[i] == 4)
		{
			c = 0;
		}
	}
	//cout<<"sub = "<<sub<<endl;
	long long d = (n*(n+1)/2) - (even-sub);
	//cout<<"sub_d = "<<d<<endl;
	return (d);
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			long long x;
			cin>>x;
			if(x%2)
				a[i] = 1;
			else
			{
				if(x%4 == 0)
					a[i] = 4;
				else
					a[i] = 2;
			}
		}
		long long x1 =  odd_mul(a,n);
		long long x2 =  mul_of_four(a,n);
		//cout<<"x2 = "<<x2<<endl;
		//cout<<"x1 = "<<x1<<endl;
		cout<<x1+x2<<endl;
		long long mul = 1;
		long long ans = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{	
				mul = mul*a[j];
				if(mul%2)
				{
					++ans;
					//cout<<a[j]<<" ";
				}
				else
				{
					if(mul%4 == 0)
					{
						++ans;
						//cout<<a[j]<<" ";
					}
				}
			}
			mul = 1;
			//cout<<endl;
		}
		//cout<<"via 2nd = "<<ans<<endl;
	}
}