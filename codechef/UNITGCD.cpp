#include<stdio.h>
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n1 1\n");	
		}
		else
		{	
			printf("%d\n",n/2);
			if(n%2==0)
			{
				for(int i=1;i<=n;i=i+2)
				{
					printf("2 %d %d\n", i,i+1);
				}
			}
			else
			{
				for(int i=2;i<=n;i=i+2)
				{
					if(i==n-1)
					{
						printf("3 1 %d %d\n", i,i+1);
					}
					else
						printf("2 %d %d\n", i,i+1);
				}	
			}
		}
	}
}