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
		long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int x = 0;
		int y = k-1;
		vector<int> peak(n,0);
		int P = 0 , max_p = 0 , idx = 0;
		for(int i = x+1 ; i<y;i++)
		{
			if(a[i] > a[i-1] && a[i] > a[i+1])
			{
				P++;
				peak[i] = 1;
			}
		}
		max_p = P;
		int l;
		for(l = 1 ; l+k-1 < n;l++)
		{
			if(a[l+k-2] > a[l+k-3] && a[l+k-2] > a[l+k-1])
			{
				P++;
				peak[l+k-2] = 1;
			}
			if(peak[l] == 1)
			{
				P--;
			}
			if(P > max_p)
			{
				max_p = P;
				idx = l;
			}
		}
		cout<<max_p+1<<" "<<idx+1<<endl;
	}
}	
