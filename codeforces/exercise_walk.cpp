#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long int l,r,u,d;
		cin>>l>>r>>d>>u;
		long int x,y,x1,x2,y1,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		long int rem1 = 0;
		long int rem2 = 0;
		long int x_fin,y_fin;
		rem1 = l-r;
		rem2 = d-u;
		x_fin = x-rem1;
		y_fin = y-rem2;
		//cout << x_fin<<endl;
		//cout << y_fin<<endl;
		long int a = 0,c=0;
		/*if(l>0)
			c++;
		if(r>0)
			c++;
		if(d>0)
			c++;
		if(u>0)
			c++;
		if(l>0 && (x-1 <=x2 && x-1 >=x1))
			a++;
		if(r>0 && (x+1 <=x2 && x+1 >=x1))
			a++;
		if(u>0 && (y+1 <=y2 && y+1 >=y1))
			a++;
		if(d>0 && (y-1 <=y2 && y-1 >=y1))
			a++;
		cout<<a<<endl;
		cout<<c<<endl;*/
		bool a1=false,a2=false,a3=false,a4=false;
		if(l>=r && (x-1 <=x2 && x-1 >=x1))
		{
			//cout<<"No1"<<endl;
			a1=true;
		}	
		if(r>=l && (x+1 <=x2 && x+1 >=x1))
		{
			a2=true;
		}
		if(u>=d && (y+1 <=y2 && y+1 >=y1))
		{
			a3=true;
		}
		if(d>=u && (y-1 <=y2 && y-1 >=y1))
		{
			a4=true;
		}
		//cout<<a1<<a2<<a3<<a4<<endl;
		if(l==r && l==0)
		{
			a1 = true;
			a2 = true;
		}
		if(u==d && u==0)
		{
			a3= true;
			a4=true;
		}
		if(x_fin <= x2 && x_fin >= x1)
		{
			if(y_fin <= y2 && y_fin >= y1)
			{
				if((l>=r == a1) && (r>=l == a2) && (u>=d == a3) && (d>=u == a4)) 
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
