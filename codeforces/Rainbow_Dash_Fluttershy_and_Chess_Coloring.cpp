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
		if(n<3)
		cout<<n<<endl;
		else
		cout<<(n/2) + 1<<endl;
	}
}
