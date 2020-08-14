#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    int sum(int n)
    {
        int s=0;
        while(n!=0)
        {
            int x = n%10;
            s+=x;
            n=n/10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        {
            vector<int> arr(36,0);
            for(int i=1;i<=n;i++)
            {
                int g = (sum(i));
                ++arr[g];
            }
            sort(arr.begin(),arr.end());
            int m = arr[35];
            cout<<"m= "<<m<<endl;
            int al = 0;
            for(int i=35;i>=0;i--)
            {
                if(arr[i] == m)
                    ++al;
            }
            return al;
        }        
        
    }
    int main()
    {
    int n;
    cin>>n;
    cout<<countLargestGroup(n)<<endl;
    }
