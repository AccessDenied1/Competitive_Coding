#include<bits/stdc++.h>
using namespace std;
int mul_plus1(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(p!=0 )
	{
		if(a%p == 0 && ((q!=b && r==c) || (q==b && r!=c) || q-r == b-c))
		{
		ans = 2;
		cout<<"yes"<<endl;
		}
	}
	else if( p!=0 && (((a-b+q)%p == 0) && r==c) || (((a-c+r)%p == 0) && q == b))
		ans = 2;
	return ans;
}
int mul_plus2(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(q!=0 && b%q == 0 && r==c)
	{
		long d1 = b/q;
		if(p*d1 != a)
			ans = 2;
	}
	else if(p!=0 && a%p == 0 && r==c)
	{
		long d1 = a/p;
		if(q*d1 != b)
			ans = 2;
	}
	else if(p!=0 && q!=0 && a%p == 0 && b%q == 0 && b/q == a/p && r!=c)
	{
		ans = 2;
	}
	else if(p!=q && (a-b)%(p-q) == 0 && r==c)
	{
		ans = 2;
	}
	else if(q!=0 && b%q == 0)
	{
		long d1 = b/q;
		if((r-p*d1) == (c-a))
			ans = 2;
	}
	else if(p!=0 && a%p == 0)
	{
		long d1 = a/p;
		if((r-q*d1) == (c-b))
			ans = 2;
	}
	else if (p!=0 && q!=0 && ((a-c+r)%p == 0) &&((b-c+r)%q == 0))
	{
		if(((a-c+r)/p) == ((b-c+r)/q))
			ans = 2;
	}
	return ans;
}
int mul_plus3_1(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(q!=0 && r!=0 && b%q == 0 && c%r == 0)
	{
		if(b/q == c/r)
		{
			long d1 = b/q;
			if(p*d1 !=a)
				ans = 2;
		}
	}
	return ans;
}
int mul_plus3_2(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(p!=q && (a-b)%(p-q)==0)
	{
		long d1 = (a-b)/(p-q);
		if(r!=0 && c%r == 0 && d1 == c/r)
			ans = 2;
	}
	return ans;
}
int mul_plus3(long p,long q, long r, long a,long b,long c)
{
	int ans = mul_plus3_1(p,q,r,a,b,c);
	ans = min(ans , mul_plus3_1(q,p,r,b,a,c));
	ans = min(ans , mul_plus3_1(r,q,p,c,b,a));
	
	ans = min(ans , mul_plus3_2(p,q,r,a,b,c));
	ans = min(ans , mul_plus3_2(p,r,q,a,c,b));
	ans = min(ans , mul_plus3_2(r,q,p,c,b,a));
	
	if(p!=q && (a-b)%(p-q) == 0)
	{
		long d1 = (a-b)/(p-q);
		long d2 = a-(p*d1);
		if(r*d1+d2 == c)
			ans = 2;
	}
	return ans;
}

int plus_mul_abc(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(r==c && q!=0 && b%q ==0 && p!=a)	//2
		ans =2;
	else if(q==b && r!=0 && c%r ==0 && p!=a)	//3
		ans = 2;
	else if(r==c && q!=0 && b%q ==0)	//4
	{
		long d2 = b/q;
		if(d2!=0 && p!=(a/d2))
			ans = 2;
	}
	else if(q==b && r!=0 && c%r ==0)	//5
	{
		long d2 = c/r;
		if(d2!=0 && p!=(a/d2))
			ans = 2;
	}
	else if(r!=0 && q!=0 && c%r ==0 && b%q == 0 && ((c/r) == (b/q)) && p!=a)	//6
		ans = 2;
	else if(r!=0 && q!=0 && c%r ==0 && b%q == 0 && ((c/r) == (b/q)))	//7
	{
		long d2 = b/q;
		if(d2!=0 && p!=(a/d2))
			ans = 2;
	}
	return ans;
}
int plus_mul_def(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(r==c && q!=b)	//1
	{
		long d1 =b-q;
		if(a!=0 && a%(p+d1) == 0)
			ans = 2;
	}
	else if(r==c && p!=a)	//2
	{
		long d1 =a-p;
		if(b!=0 && b%(q+d1) == 0)
			ans = 2;
	}
	else if(c!=0 && c%r == 0  && (p-q) == (a-b))	//3
		ans = 2;
	else if(r==c && p!=q && (a-b)%(p-q)==0)	//4
		ans = 2;
	else if(r!=0 && c%r ==0 && q!=b)	//5
	{
		long d2 = c/r;
		long d1 = b-q;
		if((p+d1)*d2 == a)
			ans = 2;
	}
	else if(r!=0 && c%r ==0 && p!=a)	//6
	{
		long d2 = c/r;
		long d1 = a-p;
		if((q+d1)*d2 == b)
			ans = 2;
	}
	else if(r!=0 && c%r ==0)	//7
	{
		long d2 = c/r;
		if((a-b)%(p-q)==0&& (d2*(p-q) == (a-b)))
			ans = 2;
	}
	return ans;
}
int plus_mul_g123(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if((q-r) == (b-c))
	{
		long d1 = b-q;
		if(a%(p+d1) == 0)
			ans = 2;
	}
	return ans;
}
int plus_mul_g456(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;
	if(c!=r && p!=q && (a-b)%(p-q) == 0)
	{
		long d2 = (a-b)/(p-q);
		long d1 = c-r;
		if(d2!=0 && (d1 == (a/d2)-p) && (d1 == (b/d2)-q))
			ans = 2;
	}
	return ans;
}
int plus_mul_g(long p,long q, long r, long a,long b,long c)
{
	int ans = 3;

	if(p!=q && (a-b)%(p-q) == 0)
	{

		long d2 = (a-b)/(p-q);
		if(d2!=0)
		{
			long d1 = (a/d2)-p;
			if((r+d1)*d2 == c)
				ans = 2;
		}
	}
	ans = min(ans, plus_mul_g123(p,q,r,a,b,c));
	ans = min(ans, plus_mul_g123(q,p,r,b,a,c));
	ans = min(ans, plus_mul_g123(r,q,p,c,b,a));

	ans = min(ans, plus_mul_g456(p,q,r,a,b,c));
	ans = min(ans, plus_mul_g456(p,r,q,a,c,b));
	ans = min(ans, plus_mul_g456(r,q,p,c,b,a));
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long p,q,r,a,b,c;
		cin>>p>>q>>r>>a>>b>>c;
		long x = a - p;
		long y = b - q;
		long z = c - r;
		long x1 = INT_MAX,y1 = INT_MAX,z1 = INT_MAX;
		if(p!=0)
			x1 = a/p;
		if(q!=0)
			y1 = b/q;
		if(r!=0)
			z1 = c/r;
		int ans = 3;
		if(x == 0 && y == 0 && z == 0){
			ans = 0;
		}
		else if((x == y && y == z) || (x1==y1 && y1 == z1)|| (x==0 && y==0) || (x==0 && z==0) || (y==0 && z==0)|| (x1 == y1 && z == 0) || (x1 == z1 && y == 0) ||(z1 == y1 && x == 0) || (x==y && z==0) || (x==z && y==0) || (y==z && x==0)){//(add any two zero)
			ans = 1;
		}
		else if(x+y==z || x+z == y || y+z == x){ //++//
				ans = 2;
		}
		else if(p!=0 && q!=0 && r!=0 && a%p == 0 && b%q ==0 && c%r == 0)//**//
		{
			if(x*y == z || x*z == y || y*z == x)
				ans = 2;
		}
		else			//+*
		{

			ans = min(ans , plus_mul_abc(p,q,r,a,b,c));	//a
			ans = min(ans , plus_mul_abc(q,p,r,b,a,c));	//b
			ans = min(ans , plus_mul_abc(r,q,p,c,b,a));	//c
			

			ans = min(ans , plus_mul_def(p,q,r,a,b,c));	//d
			ans = min(ans , plus_mul_def(p,r,q,a,c,b));	//e
			ans = min(ans , plus_mul_def(r,q,p,c,b,a));	//f

			ans = min(ans , plus_mul_g(p,q,r,a,b,c));


					//*+		
			ans = min(ans, mul_plus1(p,q,r,a,b,c));
			ans = min(ans, mul_plus1(q,p,r,b,a,c));
			ans = min(ans, mul_plus1(r,q,p,c,b,a));

			
			
			ans = min(ans , mul_plus2(p,q,r,a,b,c));
			ans = min(ans , mul_plus2(p,r,q,a,c,b));
			ans = min(ans , mul_plus2(r,q,p,c,b,a));
			
			ans = min(ans , mul_plus3(p,q,r,a,b,c));
		}
		cout<<ans<<endl;
	}
}
