#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin() , v.end());
	int t , c = INT_MAX;
	int la = v[n-1];
	int li = v[0];
	int c2 = 0;
	for(int i=li;i<=la;i++)
	{
		for(int x : v)
		{
			c2 += max(0 , abs(x-i)-1);
		}
		if(c2 < c)
		{
			t = i;
			c = c2;
		}
		c2 = 0;
	}
	cout<<t<<" "<<c<<endl;
}
