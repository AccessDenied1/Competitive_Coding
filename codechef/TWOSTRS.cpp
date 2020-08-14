#include<bits/stdc++.h>
using namespace std;
int check(string s , string st)
{
	size_t found = -1;
	int k = 0;
	while(1)
	{
		found = s.find(st , found+1);
		if(found == string::npos)
			break;
		k++;
	}
	return k;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string A,B;
		cin>>A>>B;
		int n;
		cin>>n;
		string arr[n];
		int val[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i]>>val[i];
		}
		int l1 = A.size() , l2 = B.size();
		int su = 0;
		int m_su = 0;
		for(int i = 0 ; i<l1;i++)
		{
			for(int j=0;j<l2;j++)
			{
				string ss = A.substr(0,i+1) + B.substr(l2-j-1 , j+1);
				su = 0;
				for(int k = 0;k<n;k++)
				{
					 su += check(ss , arr[k]) * val[k];
				}
				m_su = max(m_su , su);
			}
		}
		cout<<m_su<<endl;
	}
}
				
