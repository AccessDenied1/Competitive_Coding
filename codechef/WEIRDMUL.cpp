#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll mod = 998244353;

ll power(ll x, ll y) 
{
    ll res = 1; 
    x = x % mod;
 
    string b = to_string(y); 
 	ll remainderB = 0;
    
    for (int i = 0; i < b.length(); i++)
        remainderB = (remainderB * 10 + b[i] - '0') % (mod - 1); 
 	y = remainderB;
 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % mod; 
        y = y >> 1; 
        x = (x * x) % mod; 
    } 
    return res; 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		ll x;
		cin>>n>>x;
		vector<ll> v(n);
		int iszero = 0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i] == 0)
				iszero = 1;
		}
		if(iszero)
			cout<<0<<endl;
		else
		{
			vector<vector<ll>> vx(n);
			ll mul = 1;
			vx[0].push_back(v[n-1]);
			int i = 0;
			while(i < n-1)
			{
				vector<ll> A;
				A.push_back(v[n-i-2]);
				for(ll al : vx[i])
				{
					ll df = (x%mod * al%mod)%mod;
					df = (v[n-i-2]%mod + df%mod)%mod;
					A.push_back(df);
				}
				i++;
				vx[i] = A;
				A.clear();
			}
			for(int i=0; i<vx.size();i++)
			{
				for(int j=0;j<vx[i].size();j++)
				{
					//cout<<vx[i][j]<<" ";
					mul = ((mul%mod) * (vx[i][j]%mod))%mod;
				}
				//cout<<endl;
			}
			cout<<(mul*mul)%mod<<endl;
		}
	}
}
		
		
