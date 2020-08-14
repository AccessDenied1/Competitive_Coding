#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*
ABCD
ABDC
ACBD
ACDB
ADCB
ADBC
BACD
BADC
BCAD
BCDA
BDCA
BDAC
CBAD
CBDA
CABD
CADB
CDAB
CDBA
DBCA
DBAC
DCBA
DCAB
DACB
DABC
*/

int inx(char m)
{
	switch(m)
	{
		case 'A':return 0;
		case 'B':return 1;
		case 'C':return 2;
		case 'D':return 3;
	}
}

int idx(int a)
{
	switch(a)
	{
		case 12:return 0;
		case 3:return 1;
		case 6:return 2;
		case 9:return 3;
	}
}

int solve(string x, const vector< vector<int> > &mat)
{
	int arr[4];
	for(int i=0;i<4;i++)
		arr[i] = mat[inx(x[i])][i];
		
	sort(arr,arr+4,greater<int>());
	if(arr[0] ==0)
	{
		return -400;
	}
	else if(arr[1] ==0)
	{
		return (arr[0]*100 -300);
	}
	else if(arr[2] ==0)
	{
		return (arr[0]*100 + arr[1]*75  -200);
	}
	else if(arr[3] ==0)
	{
		return (arr[0]*100 + arr[1]*75 +arr[2]*50 -100);
	}
	else
	{
		return (arr[0]*100 + arr[1]*75 +arr[2]*50 + arr[3]*25 );
	}
}

int main()
{
	int t;
	cin>>t;
	int fin = 0;
	while(t--)
	{
		int n;
		cin>>n;
		int T;char m;
		vector<vector<int>> mat(4,vector<int>(4,0));
		while(n--)
		{
			cin>>m>>T;
			++mat[inx(m)][idx(T)];
		}
		string per[] = {"ABCD","ABDC","ACBD","ACDB","ADCB","ADBC","BACD","BADC","BCAD","BCDA","BDCA","BDAC","CBAD","CBDA","CABD","CADB","CDAB","CDBA","DBCA","DBAC","DCBA","DCAB","DACB","DABC"};
		int ans = -500;
		for(int i =0;i<24;i++)
		{
			int aa = solve(per[i],mat);
			//cout<<"for it = "<<aa<<endl;
			ans = max(ans,aa);
		}
		cout<<ans<<endl;
		fin+=ans;
	}
	cout<<fin<<endl;
}
