#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
  
typedef long long int ll; 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}  
ll lcm(int arr[], int n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		ll l = lcm(a,n);
		ll x = l;
		int index = 1;
		for(int i=m;i>=1;i--)
		{
			ll x2 = i*l/gcd(i,l);
			//cout<<"x2 = "<<x2<<" i = "<<i<<endl;
			if(x2>=x)
			{
				x = x2;
				index = i;
			}
		}
		cout<<index<<endl;
	}
}
