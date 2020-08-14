#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int x2 = x;
		int x3 = x;
		vector<long> v1,v2,v3;
		for(int i=0;i<n;i++)
		{
			long ss;
			cin>>ss;
			v3.push_back(ss);
			if(ss >= x)
				v1.push_back(ss);
			else
				v2.push_back(ss);
		}
		//my intial thought
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end(),greater<int>());
		int d = 0;
		for(int i=0;i<v1.size();i++)
		{
			while(v1[i] > x)
			{
				x = x*2;
				d++;
			}
			x = v1[i]*2;
			d++;
		}
		for(int i=0;i<v2.size();i++)
		{
			while(v2[i] > x)
			{
				x = x*2;
				d++;
			}
			x = v2[i]*2;
			d++;
		}
		// intial thoght ends
		
		// using the giving half method
		sort(v3.begin(),v3.end());
		int d2 = 0;
		int idx = 0;
		for(int i=0;i<v3.size();i++)
		{
			if(v3[i] >= x2)
			{
				if(i>0 && v3[i-1]*2 >= x2)
				{
					idx = i-1;
					break;
				}
				else
				{
					idx = i;
					break;
				}
			}
		}
		
		//idx  is the index
		x2 = x3;
		for(int i= idx;i<n;i++)
		{
			long f = v3[i];
			while(v3[i] > x2)
			{
				if(x2 >= (v3[i]+1)/2)
				{
					long gh = int((v3[i]+1)/2);
					d2++;
					v3[i] = max(f,(v3[i]-gh)*2); // this always set the populatin to the max 
					x2 = gh*2;
				}
				else
				{
					x2 = x2*2;
					d2++;
				}
			}
			x2 = v3[i]*2;
			d2++;
		}
		for(int i= idx-1;i>-1;i--)
		{
			long f = v3[i];
			while(v3[i] > x2)
			{
				if(x2 >= (v3[i]+1)/2)
				{
					long gh = int((v3[i]+1)/2);
					d2++;
					v3[i] = max(f,(v3[i]-gh)*2);
					x2 = gh*2;
				}
				else
				{
					x2 = x2*2;
					d2++;
				}
			}
			x2 = v3[i]*2;
			d2++;
		}
		cout<<min(d,d2)<<endl;
	}
}
