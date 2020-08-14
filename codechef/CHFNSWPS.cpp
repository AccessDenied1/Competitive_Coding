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
		long long xo = 0;
		vector<long long> A(n), B(n);
		map <long long,long long> M1,M2;
		vector<long long> v1,v2;
		long long glb_min = 10e10;
		for(int i =0;i<n;i++)
		{
			cin>>A[i];
			xo = xo^A[i];
			M1[A[i]]++;
			glb_min = min(glb_min , A[i]);
		}
		for(int i =0;i<n;i++)
		{
			cin>>B[i];
			xo ^=B[i];
			M2[B[i]]++;
			glb_min = min(glb_min , B[i]);
		}
		if(xo!=0)
			cout<<-1<<endl;
		else
		{
			for(auto al:M1)
			{
				long long diff = (al.second - M2[al.first])/2;
				
				while(diff > 0)
				{
					v1.push_back(al.first);
					diff--;
					//cout<<"ins = "<<al<<endl;
				}
			}
			for(auto al:M2)
			{
				long long diff = (al.second - M1[al.first])/2;
				
				while(diff > 0)
				{
					v2.push_back(al.first);
					diff--;
					//cout<<"ins = "<<al<<endl;
				}
			}
			
			 long long res1 = 0 , res2= 0;
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end(), greater<int>());
			/*for(int al : v1)
			{
				cout<<al<<" ";
			}
			cout<<endl;
			for(int al : v2)
			{
				cout<<al<<" ";
			}
			cout<<endl;*/
			for(int i=0;i<v1.size();i++)
			{
				long long mm = min(v1[i],v2[i]);
				if(mm < 2*glb_min)
					res1+=mm;
				else
					res1+=2*glb_min;
			}
			
			sort(v2.begin(),v2.end());
			sort(v1.begin(),v1.end(), greater<int>());
			for(int i=0;i<v1.size();i++)
			{
				long long mm = min(v1[i],v2[i]);
				if(mm < 2*glb_min)
					res2+=mm;
				else
					res2+=2*glb_min;
			}
			
			cout<<min(res1,res2)<<endl;
		}
	}
}
