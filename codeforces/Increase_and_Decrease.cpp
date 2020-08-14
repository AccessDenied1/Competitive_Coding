#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	long s = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	if(s%n == 0)
	{
		cout<<n<<endl;
	}
	else
	{
		cout<<n-1<<endl;
	}
		
}
