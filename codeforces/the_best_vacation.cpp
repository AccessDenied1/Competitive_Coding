#include<bits/stdc++.h>
using namespace std;

long long su(int n)
{
	return (1LL*n*(n+1)/2);
}
int main()
{
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	long s = 0;
	int c = 0;
	long long s2 = 0;
	long long mm = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			s = s+a[i];
			s2 = s2+su(a[i]);
			if(s>=x)
			{
				c = 1;
				break;
			}
		}
		if(c == 1)
		{
			long long s3 = su(s-x);
			s2 = s2 - s3;
			mm = max(mm,s2);
		}
		c=0;
		s=0;
		s2=0;
	}
	cout<<mm<<endl;
}	
