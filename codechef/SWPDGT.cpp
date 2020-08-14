#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int a1 = a/10;
		int a2 = a%10;
		int b1 = b/10;
		int b2 = b%10;
		int n1 = a+b;
		if(a<10 && b<10)
		{
			cout<<n1<<endl;
			return 0;
		}
		else if(a>9 && b<10)
		{
			if(a1 < b)
				cout<<((b*10)+a2+a1)<<endl;
			else
				cout<<n1<<endl;
		}
		else if(a<10 && b>9)
		{
			if(b1 < a)
				cout<<((a*10)+b2+b1)<<endl;
			else
				cout<<n1<<endl;
		}
		else
		{	
			int n2 = (b2*10)+a2+(b1*10)+a1;
			int n3 = (a1*10)+b1+(a2*10)+b2;
			int n = max(n1,n2);
			n = max(n,n3);
			cout<<n<<endl;
		}
	}
}
