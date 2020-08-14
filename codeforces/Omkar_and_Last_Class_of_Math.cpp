#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		if(n%2 == 0)
		{
			cout<<n/2<<" "<<n/2<<endl;
		}
		else
		{
			long mx = 1;
			for(int i=2;i<=sqrt(n);i++)
			{
				if(n%i == 0)
					mx = max(mx , n/i);
			}
			cout<<mx<<" "<<n-mx<<endl;
		}
		
	}
}
