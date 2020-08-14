#include<bits/stdc++.h>
using namespace std;
struct comp { 
    template <typename T> 
  
    // Comparator function 
    bool operator()(const T& l, 
                    const T& r) const
    {
        if (l.second == r.second) { 
            return l.first < r.first; 
        } 
        return l.second < r.second; 
    } 
}; 
set<pair<int, int>, comp> s1;
unordered_map<int, int> m; 
void inc(int num) 
{ 
  
    // if the element is already there 
    if (m[num]) { 

        // get the frequency of the element 
        int cnt = m[num]; 
  
        // returns an iterator pointing to 
        // position where the pair is 
        auto it1 = s1.find(make_pair(num, cnt)); 
        //auto it2 = s2.find({ cnt, num }); 

        // deletes the pair from sets 
        s1.erase(*it1); 
        //s2.erase(it2); 
    	
        // re-insert the pair by increasing 
        // frequency 
        //cout<<"inserting "<<num<<endl;
        s1.insert({ num, m[num] + 1 }); 
        //s2.insert({ m[num] + 1, num }); 
    } 
  
    // if the element is not there in the list 
    else { 
  
        // insert the element with frequency 1 
        s1.insert({ num, 1 }); 
        //s2.insert({ 1, num }); 
    } 
  
    // increase the count in hash-table 
    m[num] += 1;
    return;
}
void dec(int num) 
{ 
    // if the element exists 
    if (m[num]) { 
  
        // get the frequency of the element 
        int cnt = m[num]; 
  
        // returns an iterator pointing to 
        // position where the pair is 
        auto it1 = s1.find({ num, cnt }); 
        //auto it2 = s2.find({ cnt, num }); 
  
        // deletes the pair from sets 
        s1.erase(*it1); 
        //s2.erase(it2); 
  
        // re-insert the pair by increasing 
        // frequency 
        s1.insert({ num, m[num] - 1 }); 
        //s2.insert({ m[num] - 1, num }); 
  
        // decrease the count 
        m[num] -= 1; 
    } 
}
int an()
{
	int al1 =0 , al2 = 0;
	for(auto x:s1)
	{
		//cout<<x.first<<"->"<<x.second<<endl;
		if(x.second >=8)
		{
			al1 = 2;
		}
		else if(x.second < 8 && x.second >= 6)
		{
			al1++;
			al2++;
		}
		else if(x.second < 6 && x.second >= 4)
		{
			al1++;
		}
		else if(x.second < 4 && x.second >= 2)
		{
			al2++;
		}
		//if((al1 == 1 && al2 >=2) || al1 == 2)
			//break;
	}
	//cout<<al1<<" "<<al2<<endl;
	if((al1 == 1 && al2 >=2) || al1 == 2)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		m[v[i]]++;
	}
	for(auto x:m)
	{	
		s1.insert({x.first , x.second});
	}
	int q;
	cin>>q;

	while(q--)
	{
		char y;int x;
		cin>>y>>x;

		if(y == '-')
		{

			dec(x);
		}
		else
		{
			//cout<<x<<" sub"<<endl;
			inc(x);
			//cout<<"doo"<<endl;
		}
		int al1 = 0 , al2 = 0;
		int b = an();
		//cout<<"done"<<endl;
		if(b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		//if(al1 == 1 && al2 == 2 || al1 == 2)
			//cout<<"YES"<<endl;
		//else
			//cout<<"NO"<<endl;
		
	}
}
