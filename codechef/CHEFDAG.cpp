#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > vp; 
void sortArr(int arr[],int n) 
{ 

    for (int i = 0; i < n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    }
    sort(vp.begin(), vp.end());
}
void min_index(vector<vector<int>> mat)
{
	int min_sum = 0,idx = 0;
	int ss = 0;
	for(int i = 0;i<mat.size();i++)
	{
		for(int j = 0;j<mat.size();j++)
		{
			ss += mat[j][i];
		}
		sarr[i] = ss;
	}
	sortArr(sarr,n);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		vector<vector<int>> mat(n,n);
		for(int i =0 ;i<n;i++)
		{
			cin>>a[i];
			--a[i];
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				mat[i][j] = 0;
			}
		}
		for(int i = 0;i<n-1;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				mat[a[i]][a[j]] = 1;
			}
		}
		k--;
		while(k--)
		{
			for(int i =0 ;i<n;i++)
			{
				cin>>a[i];
				--a[i];
			}
			for(int i = 0;i<n-1;i++)
			{
				for(int j = i+1;j<n;j++)
				{
					if(mat[a[j]][a[i]] == 1)
						{
							mat[a[j]][a[i]] = 0;
							//cout<<"yes3"<<endl;
							//cout<<"a = "<<a[i]<<" b = "<<a[j]<<endl;
						}
						
				}
			}
		}
		cout<<"mat"<<endl;
		for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<n;j++)
				{
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		vector<int> ans(n,-1);
		//cout<<"yes2"<<endl;
		min_index();
		sortArr(n);
		for(int i=0;i<vp.size();i++)
		{
			inx = vp[i].second;
			for(int j=0;j<n;j++)
			{
				if(mat[j][inx] == 1)
				{
					ans[j] = i;
					for(int z = 0;z<n;z++)
						mat[j][z] = 0;
						break;
				}
			}
		}
		vector<int> indeg(n,0);
		for(int i=0;i<n;i++)
		{
			if(ans[i] !=-1)
				indeg[ans[i]] = 1;
		}
		int sum = 0;
		for(int i=0;i<n;i++)
			sum += indeg[i];
		cout<<n-sum<<endl;
			
		for(int i=0;i<n;i++)
			cout<<ans[i]+1<<" ";
		cout<<endl;
	}
}
