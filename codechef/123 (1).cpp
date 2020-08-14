#include <bits/stdc++.h> 
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second 
#define S size()
#define nmax (ll)(1e6)
#define mod (ll)(1e6)
#define mset(a,k) memset(a,k,sizeof(a));
#define fr(i, x, y) for ( ll i = x; i < y;i++)
#define dr(i, x, y) for ( ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll,vll ,greater<ll>>
#define mapcl map<char,ll>
#define mapll map<ll,ll>
#define mapsl map<string,ll>
#define vi vector<ll>
#define vs vector<string>
#define psi pair<string,ll> 
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
using namespace std;
void fast(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}  
//----------------------------------------FUNCTIONS------------------------------------- 
vi primes;
void sieve(ll n){
    vector<bool> prime(n+1,true);
    for(ll p = 2; p * p <= n; p++){
        if(prime[p] == true){
            for (ll i = p*2; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
       if(prime[p])
          primes.pb(p);
}

ll modexpo(ll a,ll b)
{
    if(b==0)
    return 1;
    if(b==1)
    return a;
    ll temp=modexpo(a,b/2);
    if(b%2)
    return (temp%mod*temp%mod*a)%mod;
    return (temp%mod*temp%mod)%mod;
}
ll gcd(ll x,ll y )						{if(y==0) return x;return gcd(y,x%y);}
ll lcm(ll a, ll b)						{return (a*b)/gcd(a, b);}
ll logx(ll base, ll num)				{int cnt=0;while(num!=1){num/=base; ++cnt;}return cnt;}
vi vin(ll n)							{vi a(n);fr(i, 0, n) cin>>a[i];return a;}
void out(vi a)							{for(int i=0;i<(ll)a.S;i++) { cout<<a[i]<<" "; }cout<<endl;}
void in(ll *a, ll n)        			{for(ll i=0;i<n;i++)cin>>a[i];}
void out(ll *a,ll n)					{fr(i,1,n+1){cout<<a[i]<<" ";}cout<<'\n';}
void out1(vi v)							{fr(i,0,(ll)v.S){cout<<v[i]<<" ";}cout<<endl;}
//----------------------------------------START------------------------------------------- 	
int solve(); 
int main()
{
	fast();
	solve();
		
}
5 4 3 2 1
v1 = 1 , 5
swap(a[0] , a[4])
1 4 3 2
int solve()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll  n,k;
		cin>>n>>k;
		ll a[n];
		in(a,n);
		ll ans=0;
		vector<vi> v;
		for(ll i=0;i<n;i++){
			vi v1;
			v1.pb(i+1);
			ll cnt=0;
			while(a[i]!=i+1)
			{
				v1.pb(a[i]);
				swap(a[i],a[a[i]-1]);
				cnt++;
				if(cnt==2)
				{
					v.push_back(v1);
					v1.clear();
					v1.push_back(i+1);
					ans++;
					cnt=0;
				}
			}
			if(cnt)
			{
				for(ll j=i;j<n;j++)
				{
					if(a[j]!=j+1)
					{
						v1.insert(v1.begin()+1,j+1);
						swap(a[j],a[v1[2]-1]);
						break;
					}
				}
				if(v1.S!=3)
				{
					ans=-1;
					break;
				}
				ans++;
				v.pb(v1);
			}
		}
		if(ans==-1 || v.S>k)
		{
			cout<<-1<<'\n';
			continue;
		}
		cout<<v.S<<'\n';
		for(auto i:v)
			cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<'\n';
	}
	return 0;
}  

