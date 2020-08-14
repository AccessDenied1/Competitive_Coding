#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int phi[n+1];
	
	for(int i=1;i<=n;i++)
		phi[i] = i;
		
	for(int p=2;p<=n;p++)
	{
		if(phi[p] == p)
		{
			phi[p] = p-1;
			for(int i=2*p;i<=n;i=i+p)
			{
				phi[i] = (phi[i]/p)*(p-1);
			}
		}
	}
	cout<<phi[n]<<endl;
}

