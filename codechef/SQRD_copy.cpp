#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define MAX 7
#define pb push_back 
vector<int> primes; 

// k_cnt stores count of prime factors of k 
// current_map stores the count of primes 
// in the current sub-array 
// cnts[] is an array of maps which stores 
// the count of primes for element at index i 
unordered_map<int, int> k_cnt, current_map, cnts[MAX]; 

// Function to store primes in 
// the vector primes 
void sieve() 
{ 

	int prime[MAX]; 
	prime[0] = prime[1] = 1; 
	for (int i = 2; i < MAX; i++) { 
		if (prime[i] == 0) { 
			for (int j = i * 2; j < MAX; j += i) { 
				if (prime[j] == 0) { 
					prime[j] = i; 
				} 
			} 
		} 
	} 

	for (int i = 2; i < MAX; i++) { 
		if (prime[i] == 0) { 
			prime[i] = i; 
			primes.pb(i); 
		} 
	} 
} 

// Function to count sub-arrays whose product 
// is divisible by k 
ll countSubarrays(int* arr, int n, int k) 
{ 

	// Special case 
	if (k == 1) { 
		cout << (1LL * n * (n + 1)) / 2; 
		return 0; 
	} 

	vector<int> k_primes; 

	for (auto p : primes) { 
		while (k % p == 0) { 
			k_primes.pb(p); 
			k /= p; 
		} 
	} 

	// If k is prime and is more than 10^6 
	if (k > 1) { 
		k_primes.pb(k); 
	} 

	for (auto num : k_primes) { 
		k_cnt[num]++; 
	} 

	// Two pointers initialized 
	int l = 0, r = 0; 

	ll ans = 0; 

	while (r < n) { 

		// Add rth element to the current segment 
		for (auto& it : k_cnt) { 

			// p = prime factor of k 
			int p = it.first; 

			while (arr[r] % p == 0) { 
				current_map[p]++; 
				cnts[r][p]++; 
				arr[r] /= p; 
			} 
		} 

		// Check if current sub-array's product 
		// is divisible by k 
		int flag = 0; 
		for (auto& it : k_cnt) { 
			int p = it.first; 
			if (current_map[p] < k_cnt[p]) { 
				flag = 1; 
				break; 
			} 
		} 

		// If for all prime factors p of k, 
		// current_map[p] >= k_cnt[p] 
		// then current sub-array is divisible by k 

		if (!flag) { 

			// flag = 0 means that after adding rth element 
			// segment's product is divisible by k 
			ans += n - r; 

			// Eliminate 'l' from the current segment 
			for (auto& it : k_cnt) { 
				int p = it.first; 
				current_map[p] -= cnts[l][p]; 
			} 

			l++; 
		} 
		else { 
			r++; 
		} 
	} 

	return ans; 
}

int main()
{
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    sieve(); 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			long long x;
			cin>>x;
			if(x%2)
				a[i] = 1;
			else
			{
				if(x%4 == 0)
					a[i] = 4;
				else
					a[i] = 2;
			}
		}
		//
		long long x2 =  countSubarrays(a,n,4);
		k_cnt.clear(); current_map.clear(); 
		cnts[MAX].clear();
		long long x1 =  countSubarrays(a,n,2);
		x1 = (n*(n+1))/2 - x1;
		//cout<<x2+x1<<endl;
		cout<<"x1 = "<<x1<<endl;
	}
}
