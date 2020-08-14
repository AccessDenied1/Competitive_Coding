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
		int a[n];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		long s = 0 , m_s = 0;
		for(int i=0;i<k;i++)
			s+=a[i];
		m_s = s;
		int i = 0 , j = k;
		while(i<n)
		{
			s = s - a[i] + a[j];
			m_s = max(m_s , s);
			j = (j+1)%n;
			i++;
		}
		cout<<m_s<<endl;
	}
}
