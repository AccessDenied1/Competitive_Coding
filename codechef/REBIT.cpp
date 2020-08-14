#include<iostream>
using namespace std;

int solve_1(string);
int solve_0(string);
int solve_a(string);

//long ans = 1.0;
float prob_1 = 0.25,prob_0 = 0.25,prob_a = 0.25,anything = 1.0;
int solve_1(string s)
{
	static int ans = 1233.0;
	
		if(s[1] == '&')
		{
			cout<<"yes1"<<endl;
			int n = s.size();
			return ((prob_1)*solve_1(s.substr(2,n-2)));
		}
		else if(s[1] == '|')
		{
			int n = s.size();
			return ((prob_1)*anything + (1*solve_1(s.substr(2,n-2))));
		}
		else if(s[1] == '^')
		{
			int n = s.size();
			return ((prob_1 + prob_0) + (prob_1*solve_0(s.substr(2,n-2))) 
									 + (prob_0*solve_1(s.substr(2,n-2))));
		}
		else
		{
			cout<<"yes2"<<endl;
			//ans *= prob_1;
			return prob_1;
			cout<<"ans1 = "<<ans<<endl;
		}
		return ans;
}
int solve_0(string s)
{
		static int ans = 1.0;

		if(s[1] == '&')
		{
			int n = s.size();
			ans *= (prob_0)*anything + (1*solve_0(s.substr(2,n-2)));
		}
		else if(s[1] == '|')
		{
			int n = s.size();
			ans *= (prob_0)*solve_0(s.substr(2,n-2));
		}
		else if(s[1] == '^')
		{
			int n = s.size();
			ans *= (prob_1 + prob_0) + (prob_1*solve_1(s.substr(2,n-2))) 
									 + (prob_0*solve_0(s.substr(2,n-2)));
		}
		else
		{
			ans *= prob_0;
		}
}
int solve_a(string s)
{
		static int ans = 1.0;

		if(s[1] == '&')
		{
			int n = s.size();
			ans *= (prob_a)*solve_1(s.substr(2,n-2)) 
									+ (prob_1)*solve_a(s.substr(2,n-2))
									+ (prob_a)*solve_a(s.substr(2,n-2));
		}
		else if(s[1] == '|')
		{
			int n = s.size();
			ans *= (prob_a)*solve_0(s.substr(2,n-2)) 
									+ (prob_0)*solve_a(s.substr(2,n-2))
									+ (prob_a)*solve_a(s.substr(2,n-2));
		}
		else if(s[1] == '^')
		{
			int n = s.size();
			ans *= (prob_0*solve_a(s.substr(2,n-2))) + (prob_a*solve_0(s.substr(2,n-2)));
		}
		else
		{
			ans *= prob_a;
		}
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans = solve_1(s);
		int n = s.size();
		//cout<<s.substr(2,n-2)<<endl;
		cout<<ans*prob_1<<endl;
	}
}