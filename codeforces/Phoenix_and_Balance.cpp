#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x = 1;
		long s1 = 0;
		long s2= 0;
		if(n == 2)
			cout<<2<<endl;
		else
		{
			long a[n];
			for(int i = 0;i<n;i++)
				a[i] = pow(2,i+1);
			vector<int> used(n,0);
			for(int i = n-1; i>=0;i--)
			{
				if(used[i])
					continue;
				//cout<<"yes"<<endl;
				int al1 = a[i];
				int mi = INT_MAX;
				used[i] = 1;
				int idx = i-1;
				int A = 0,B = 0;
				for(int j = i-1;j>=0;j--)
				{
					int al2 = a[j];
					int p = 0, q = 0;
					if(!used[j])
					{
						if(s1<s2)
						{
							p = s1 + al1;
							q = s2 + al2;
						}
						else
						{
							q = s2 + al1;
							p = s1 + al2;
						}
						int diff = abs(p-q);
						//cout<<"diff = "<<diff<<endl;
						if(diff < mi)
						{
							idx = j;
							A = al1;
							B = al2;
							mi = diff;
						}
					}
				}
				//cout<<"A == "<<A<<endl;
				//cout<<"B == "<<B<<endl;
				if(s1<s2)
				{
					s1+=A;
					s2+=B;
				}
				else
				{
					s1+=B;
					s2+=A;
				}
				used[idx] = 1;
			}		
			cout<<(abs(s1-s2))<<endl;
		}
	}
}
