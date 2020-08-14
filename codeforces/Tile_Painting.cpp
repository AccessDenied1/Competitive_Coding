#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	if(n==1)
		cout<<1<<endl;
	else
	{
		for(long long i=2;i<=n;i++)
		{
			if(n%i == 0)
			{
				if(i == n)
					cout<<n<<endl;
				else
					cout<<n/i<<endl;
				break;
			}
		}
	}
}
