#include<iostream>
using namespace std;
#include<bits/stdc++.h>
bool comp(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , k;
		cin>>n>>k;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0 ;i<n;i++)
		{
			cin>>a[i];
			b[i] = a[i];
		}
		int s = 0;
		map<int,int> M;
		for(int i = 0;i<n/2;i++)
		{
			s = a[i] + a[n-i-1];
			if(M.find(s) == M.end())
			{
				M[s] = 1;
			}
			else
			{
				M[s]++;
			}
		}
		vector<pair<int,int>> vec;
		int mm = 0;
		for(auto x : M)
		{
			vec.push_back(make_pair(x.first , x.second));
		}
		sort(vec.begin(),vec.end() , comp);
		int al = 0;
		int ans = 0,j;
		for(j= 0;j<vec.size();j++)
		{
			//cout<<"sum = "<<vec[j]<<endl;
			for(int i = 0;i<n/2;i++)
			{
				al++;
				s = a[i] + a[n-i-1];
				if(s == vec[j].first)
					continue;
				else
				{
					ans++;
					if(a[i] > a[n-i-1])
					{
						a[n-i-1] = vec[j].first - a[i];
						if(a[n-i-1] <1 || a[n-i-1] > k)
						{
							a = b;
							break;
						}
					}
					else
					{
						a[i] = vec[j].first - a[n-i-1];
						if(a[i] <1 || a[i] > k)
						{
							a = b;
							break;
						}
					}
				}
			}
			if(al == (n/2))
				break;
			al = 0;
			ans = 0;
		}
		if(ans == 0 && j == vec.size())
			cout<<(n/2)<<endl;
		else	
			cout<<ans<<endl;
	}
	
}
		
		
