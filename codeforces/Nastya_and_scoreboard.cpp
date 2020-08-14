#include<bits/stdc++.h>
using namespace std;
int n , k;
vector<string> str;
vector<string> nums = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
void print()
{
	for(string a : str)
	{
		for(int i = 0;i<10;i++)
		{
			if(nums[i] == a)
				cout<<i;
		}
	}
	cout<<endl;
}
string convert(string a)
{
	int mi = 10 ;
	int al = 0;
	string f;
	for(string x : nums)
	{
		for(int i = 0 ; i< 7;i++)
		{
			if(x[i]!=a[i])
			{
				al++;
			}
		}
		//cout<<"al = "<<al<<endl;
		if(al <= mi)
		{
			mi = al;
			f = x;
		}
		al = 0;
	}
	k = k - mi;
	return f;
}
int check(string a , int i)
{
	int al = 0;
	int ss = 0;
	int j;
	for(j = 9 ; j >=0;j--)
	{
		for(int i = 0 ; i< 7;i++)
		{
			if(a[i] == 0 && nums[j][i] == 1)
			{
				ss++;
			}
			if(a[i] == 1 && nums[j][i] == 0)
			{
				al = 1;
				break;
			}
		}
		if(al == 0 && ss<=k)
		{
			str[i] = nums[j];
			break;
		}
		if()
		al = 0;
		ss = 0;
	}
	if(j==-1)
		return -1;
	return ss;
}	
int main()

{
	cin>>n>>k;
	str.resize(n);
	for(int i=0;i<n;i++)
		cin>>str[i];
	int c=0;
	for(int i = 0;i<n;i++)
	{
		string a = str[i];
		for(string b : nums)
		{
			if(a==b)
			{
				cout<<"b = "<<b<<endl;
				c=1;
			}
		}
		if(c == 0)
		{
			str[i] = convert(a);
		}
		c = 0;
	}
	for(string g : str)
		cout<<g<<" ";
	int h;
	if(k<0)
		cout<<-1<<endl;
	else if(k>0)
	{
		for(int i = 0;i<n;i++)
		{
			string a = str[i];
			h = check(a,i);
			if(h == -1)
				break;
			k = k-h;
		}
		if(h == -1)
			cout<<-1<<endl;
		else
			print();
	}
	else
		print();
	
}
