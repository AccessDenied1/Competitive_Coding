#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[9][9];
		for(int i=0;i<9;i++)
		{
			string x;
			cin>>x;
			for(int j=0;j<9;j++)
			{
				a[i][j] = int(x[j]) - 48;
			}
		}
		a[0][0] = a[0][0] == 1 ? 2 : 1;
		a[3][1] = a[3][1] == 1 ? 2 : 1;
		a[6][2] = a[6][2] == 1 ? 2 : 1;
		a[1][3] = a[1][3] == 1 ? 2 : 1;
		a[4][4] = a[4][4] == 1 ? 2 : 1;
		a[7][5] = a[7][5] == 1 ? 2 : 1;
		a[2][6] = a[2][6] == 1 ? 2 : 1;
		a[5][7] = a[5][7] == 1 ? 2 : 1;
		a[8][8] = a[8][8] == 1 ? 2 : 1;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
}				
