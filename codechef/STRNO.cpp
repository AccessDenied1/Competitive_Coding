#include<cmath>
#include<iostream>
using namespace std;

long int prime_fac(long int x)
{
    long int pr = 0;
    while(x%2==0)
    {
        //cout<<2<<endl;
        pr++;
        x=x/2;
    }
    for(long long i=3;i*i<=(x);i=i+2)
    {
        while(x%i==0)
        {
            //cout<<i<<endl;
            pr++;
            x=x/i;
        }
    }
    if(x>2)
    {
        pr++;
    }    //cout<<x<<endl;
    return pr;
}
int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif

    int t;
    cin>>t;
    while(t--)
    {
        long int x,k;
        cin>>x>>k;
        long int pr = prime_fac(x);
       // cout<<pr<<endl;
        if(pr<k)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
}