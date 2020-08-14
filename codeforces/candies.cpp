#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		int k = 2;
		long p;
		while(1)
		{
			p = pow(2,k)-1;
			if(n%p == 0)
			{
				break;
			}
			k++;
		}
		cout<<n/p<<endl;
	}
}
