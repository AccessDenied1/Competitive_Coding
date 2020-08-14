#include<bits/stdc++.h>
using namespace std;
int cc(long x,long y,long l,long r)
{
	long p = (x&l)*(y&l);
	int gh = l;
	for(long i = l+1;i<=r;i++)
	{
		long p_n = (x&i)*(y&i);
		//cout<<"pro = "<<p_n<<" for i = "<<i<<endl;
		if(p_n > p)
		{
			p = p_n;
			gh = i;
		}
	}
	return gh;
}
string decToBinary(long n) 
{ 
    string s = ""; 
    while (n > 0) 
    { 
      s = s + to_string(n % 2); 
      n = n / 2;
    }
    reverse(s.begin(),s.end());
    return s;
}
long binaryToDecimal(string n) 
{ 
    string num = n; 
    long dec_value = 0; 
    long base = 1; 
    long len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    }
    return dec_value; 
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long x,y,l,r;
		cin>>x>>y>>l>>r;
		long s = 1;
		if(x==0||y==0)
			cout<<0<<endl;
		else
		{
			long long pow = 0;
			long rrr = r;
			long z = r;
			string R = decToBinary(r);
			//cout<<"R  = "<<R<<endl;
			int len = R.size();
			string dd = "" ;
			string st = "";
			for(int i=0;i<len;i++)
			{
				st +='1';
			}
			for(int i = 0 ;i<len;i++)
			{
				if(R[i] == '1')
				{
					dd = R.substr(0,i)+ "0";
					if(i != len-1) 
						dd += st.substr(i+1,len-i-1);
					//cout<<"dd = "<<dd<<endl;
					long r2 = binaryToDecimal(dd);
					r2 = r2&(x|y);
					long long pow2 = (x&r2)*(y&r2);
					if(pow2 >= pow)
					{
						z = r2;
						pow = pow2;
					}
				}
			}
			r = r&(x|y);
			long long pow2 = (x&r)*(y&r);
			if(pow2 > pow)
			{
				z = r;
				pow = pow2;
			}
			cout<<z<<endl;
			//cout<<"via other = "<<cc(x,y,l,rrr)<<endl;
		/*
			long z = 1;
			while(z<=r)
			{
				z = 2*z + 1;
			}
			long hh = z&(x|y);
			if(hh > r)
				hh = ((z-1)/2)&(x|y);
			cout<<hh<<endl;*/
		}
	}
}
