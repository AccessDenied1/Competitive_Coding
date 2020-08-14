#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	//cout<<"input is "<<n<<" "<<q<<endl;
	vector<long long> h(n) , a(n);
	for(int i=0;i<n;i++)
		cin>>h[i];
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(q--)
	{
		int x;
		long long b,c;
		cin>>x>>b>>c;
		//cout<<"input is "<<x<<" "<<b<<" "<<c<<endl;
		b--;
		if(x == 1)
		{
			//cout<<"yes"<<endl;
			a[b] = c;
		}
		else
		{
			c--;
			int al = 0;
			long long s = 0;
			if(b > c)
			{
				s+=a[c];
				int curr = c;
				for(int i = c+1;i<=b;i++)
				{
					if(h[i] > h[curr])
					{
						s+=a[i];
						curr = i;
					}
					if(h[i] > h[b])
						break;
				}
				if(curr == b)
				{
					cout<<s<<endl;
					al=1;
				}
			}
			else
			{	
				// c = 3
				// b = 1
				s+=a[c];// 4
				int curr = c;//5
				for(int i = c-1;i>=b;i--)
				{
					if(h[i] > h[curr])
					{
						s+=a[i];
						curr = i;
					}
					if(h[i] > h[b])
						break;
				}
				if(curr == b)
				{
					cout<<s<<endl;
					al=1;
				}
			}
			if(al == 0)
				cout<<-1<<endl;
		}
	}
}
