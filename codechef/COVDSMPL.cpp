#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		int mat[n][n];
		memset(mat, 0, sizeof(mat)); 
		int tol;
		cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
		cin>>tol;
		int s = 0 , s1 = 0;
		int cx = 0;
		for(int i=1;i<=n;i++)
		{
			int r = 0;
			cout<<1<<" "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
			cin>>r;
			s1 = 0;
			for(int j=1;j<=n;j++)
			{
				cout<<1<<" "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
				cin>>mat[i-1][j-1];
				s1 +=mat[i-1][j-1];
				s +=mat[i-1][j-1];
				if(s == tol)
				{
					cx = 1;
					break;;
				}
				if(s1 == r)
					break;
			}
			if(cx == 1)
				break;
		}
		cout<<2<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		int x;
		cin>>x;
		if(x != 1)
			break;
	}
}
		
