#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr , int a, int b , int c)
{
	int t1 = arr[b];
	int t2 = arr[c];
	arr[b] = arr[a];
	arr[c] = t1;
	arr[a] = t2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
			arr[i] -= 1;
		int ss = 0;
		vector<int> ans;
		int flag=1;
		for(int g=0;g<50;g++)
		{
			int i = 0;
			for(int cnt=0;cnt<n;cnt++)
			{
				if(arr[i] == i)
				{
					i++;
					continue;
				}
				int c = arr[arr[i]];
				if(c!=i)
				{
					ans.push_back(i);
					ans.push_back(arr[i]);
					ans.push_back(c);
					ss++;
					rotate(arr,i,arr[i],c);
				}
				else
					i++;
				if(is_sorted(arr.begin(),arr.end()))
					break;
			}
			i=0;
			for(int cnt=0;cnt<n;cnt++)
			{
				if(arr[i] == i)
				{
					i++;
					continue;
				}
				int c = arr[arr[i]];
				if(arr[arr[i]]==i)
				{
					for(int j=0;j<n;j++)
					{
						if(j!=i && j!=arr[i] && j!=arr[j])
						{
							c = j;
							break;
						}
					}
					if(c==arr[arr[i]])
					{
						flag=0;
						break;
					}
					ans.push_back(i);
					ans.push_back(arr[i]);
					ans.push_back(c);
					ss++;
					rotate(arr,i,arr[i],c);
				}
				else
		        {
				    ans.push_back(i);
					ans.push_back(arr[i]);
					ans.push_back(c);
					ss++;
					rotate(arr,i,arr[i],c);
				}
				if(is_sorted(arr.begin(),arr.end()))
					break;
				i++;

			}
			if(flag==0)
				break;
			if(is_sorted(arr.begin(),arr.end()))
				break;
		}
		if(flag==0)
			cout<<-1<<"\n";
		else
		{
			cout<<ss<<endl;
			for(int i=0;i<3*ss;i = i+3)
			{
				cout<<ans[i]+1<<" "<<ans[i+1]+1<<" "<<ans[i+2]+1<<endl;
			}
		}
	}
}
