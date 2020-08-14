#include <bits/stdc++.h> 
using namespace std;
void getSubset(int n,vector<vector<int>> &vec)
{
	vector<int> kk;
	for (int i = 0; i < (1<<n); i++)
	{
    	for (int j = 0; j < n; j++)
    	{ 
        	if ((i & (1 << j)) > 0)
        	{
        		kk.push_back(j);
            	//cout<<j<<" ";
            }
        }
        vec.push_back(kk);
        kk.clear();
		//cout<<endl;
	}
	//cout<<"size= "<<vec.size()<<endl;
}
void print(vector<int> vec)
{
	int n = vec.size();
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}
int minSwaps(vector<int> arr, int n) 
{
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
    sort(arrPos, arrPos + n); 
    vector<bool> vis(n, false); 
    int ans = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    return ans; 
}
void findPermutations(vector<int> a, int n , vector<vector<int>> &V) 
{
    do
    {
     	V.push_back(a);
    }while (next_permutation(a.begin() ,a.end()));
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> ar(n);
		vector<int> Ar(n);
		vector<int> Ar2(n);
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			Ar[i] = ar[i];
		}	
		int X[m],Y[m];
		
		for(int i=0;i<m;i++)
			cin>>X[i]>>Y[i];
			
		int mm = 0;
		int mi = minSwaps(ar,n);
		int d1=0,d2=0,d3=0,d4=0;
		for(int i = 0 ; i<m;i++)
		{
			int x = X[i] - 1;
			int y = Y[i] - 1;
			swap(ar[x],ar[y]);
			int d1 = minSwaps(ar,n);
			Ar2 = ar;
			for(int j = 0;j<m;j++)
			{
				d2 = d1;
				if(j!=i)
				{
					int x1 = X[j]-1;
					int y1 = Y[j]-1;
					swap(ar[x1],ar[y1]);
					int d22 = minSwaps(ar,n);
					if(d22 >= d2)
					{
						ar = Ar2;
						cout<<"x1 = "<<x1<<" y1 = "<<y1<<endl;
					}
					else
						d2 = d22;
				}
			}
			ar = Ar2;
			for(int j = m-1;j>-1;j--)
			{
				d3 = d1;
				if(j!=i)
				{
					int x1 = X[j]-1;
					int y1 = Y[j]-1;
					swap(ar[x1],ar[y1]);
					int d33 = minSwaps(ar,n);
					if(d33 >= d3)
						ar = Ar2;
					else
						d3 = d33;
				}
			}
			mi = min(min(d3,d2),mi);
			ar = Ar;
		}
		cout<<mi<<endl;
	}
}
