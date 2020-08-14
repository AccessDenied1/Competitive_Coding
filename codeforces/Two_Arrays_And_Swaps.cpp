#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n] , b[n];
		for(int i =0;i<n;i++)
			cin>>a[i];
		for(int i =0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		int s1 = 0, s2 = 0;
		int l = 0;
		int m = n-1;
		while(l<k && l<n )
		{
			if(a[l] < b[m])
				swap(a[l] , b[m]);
			else
				break;
			l++;
			m--;
		}
		cout<<accumulate(a,a+n , 0)<<endl;
	}
}
