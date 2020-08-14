#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.size();
		vector<int> v;
		int x = 1;
		int al = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i] == '1')
			{
				x = 1;
				while(i < n-1 && s[i+1] == '1')
				{
					x++;
					i++;
				}
				v.push_back(x);
				
			}
		}
		sort(v.begin() , v.end() , greater<int>());
		int y = v.size();
		//cout<<"y = "<<y<<endl;
		int ans = 0;
		for(int i = 0;i<y;i = i+2)
		{
			ans +=v[i];
		}
		
		cout<<ans<<endl;
	}
}
