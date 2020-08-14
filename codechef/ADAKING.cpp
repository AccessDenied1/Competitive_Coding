#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		vector<vector<char>>v(8, vector<char>(8,'X'));
		v[0][0] = 'O';
		int al = 0;
		k--;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(k == 0)
				{
					al = 1;
					break;
				}
				if(v[i][j] == 'X')
				{	
					v[i][j] = '.';
					k--;
				}
				
			}
			if(al == 1)
				break;
		}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cout<<v[i][j];
			}
			cout<<endl;
		}	
	}
}
