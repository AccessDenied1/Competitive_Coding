#include<bits/stdc++.h>
using namespace std;
int cc(long x,long y,long l,long r)
{
	long p = (x&l)*(y&l);
	int gh = l;
	for(long i = l+1;i<=r;i++)
	{
		long p_n = (x&i)*(y&i);
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
long calc(long z, long x, long y , long l)
{
	long po = x|y;
	int i = 0;
	long newz = z;
	//cout<<z<<endl;
	//cout<<po<<endl;
	while(po!=0)
	{
		//cout<<(po&1)<< " "<<(z&1)<<endl;
		if(!(po&1) && ((z&1)))
		{
			//cout<<"yes for "<<i<<endl;
			newz = newz - pow(2,i);
		}
		if(newz < l)
		{
			newz = newz+pow(2,i);
			break;
		}
		po = po >>1;
		z = z>>1;
		i++;
	}
	return newz;
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long x,y,l,r;
		cin>>x>>y>>l>>r;
		long rr = r;
		long s = 1;
		if(x==0||y==0)
			cout<<l<<endl;
		else if((x|y) >= l && (x|y) <=r)
			cout<<(x|y)<<endl;
		else
		{
			//cout<<"x or y "<<decToBinary(x|y|l)<<endl;
			vector<long> R2;
			long long poww = 0;
			long z = r;
			long rr = r;
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
					//cout<<"doing "<<r2<<" and "<<(x|y)<<endl;
					r2 = r2&(x|y|l);
					if(r2<l)
					continue;
					R2.push_back(r2);
				}
			}
			long fg = r&(x|y|l);
			if(fg >= l )
				R2.push_back(fg);
			sort(R2.begin(),R2.end());
			for(long r2 : R2)
			{
				//cout<<"r2 = "<<(r2)<<endl;
				long long pow2 = (x&r2)*(y&r2);
				if(pow2 > poww)
				{
					z = r2;
					poww = pow2;
				}
			}
			if(((x&z)*(y&z)) == 0)
				cout<<l<<endl;
			else
			{
				//cout<<"z = "<<z<<endl;
				if(l!=0)
					cout<<calc(z,x,y,l)<<endl;
				else
					cout<<z<<endl;
			}
		}
	}
}
