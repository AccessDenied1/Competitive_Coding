#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int k,x;
		cin>>k>>x;
		int ans = 0;
		vector<int> arr(26,0);
		for(int i=0;i<s.size();i++)
		{
			char c = s[i];
			int idx = int(c) - 97;
			++arr[idx];
			if(arr[idx] > x)
				k--;
			else
				++ans;
			if(k<0)
				break;
		}
		
		cout<<ans<<endl;
	}
}
			
