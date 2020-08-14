#include<bits/stdc++.h>
using namespace std;
vector<long long > vec;
int main()
{
	long long n;
	cin>>n;
	long long s = 0;
		long long i = 0;
	while(s<=0)
	{
		i=i+1;
		s = i*(i+1)-(2*n);
		vec.push_back(s);
	}
	/*int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long s = 0;
		long long i = 0;
		while(s<=n)
		{
			i=i+1;
			s = s+i;
		}
		s = s - i;
		i = i--;
		cout<<n-s<<endl;
	}*/
	cout<<i<<endl;
		
}
	
