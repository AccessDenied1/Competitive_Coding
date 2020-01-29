#include<stdio.h>
#include<math.h>
void max_heapify(int A[],int i,int n)
{
	int l=2*i,r=(2*i+1),largest,temp;
	
	if(l<=n&&A[l-1]>A[i-1])
	{
		largest=l;	
	}
	else
	{
		largest=i;
	}
	if(r<=n&&A[r-1]>A[largest-1])
	{
		largest=r;	
	}
	if(largest!=i)
	{
		temp=A[i-1];
		A[i-1]=A[largest-1];
		A[largest-1]=temp;	
	}
	if((l>n||r>n)||largest==i)
	{
		return;
	}
	max_heapify(A,largest,n);
}

void build_heap(int A[],int n)
{
	int i;
	int leaf=(n/2);
	for(i=leaf;i>=1;i--)
	{
		max_heapify(A,i,n);
	}
}

void heapsort(int A[],int n)
{
	int i=n,temp,size=n;
	build_heap(A,n);
	for(i=n;i>1;i--)
	{
		temp=A[i-1];
		A[i-1]=A[0];
		A[0]=temp;
	
		size--;
		max_heapify(A,1,size);
	}

}

int main()
{
	int n,i;
	printf("Enter the size of array\n");
	scanf("%d", &n);
	int A[n];
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	heapsort(A,n);
	printf("HEAP\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",A[i]);
	}
}
