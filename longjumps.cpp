#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int chck(ll x,int n){
	int lo=0,hi=n-1;
	//int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(a[mid]==x)return 1;
		else if(a[mid]<x)lo=mid+1;
		else hi=mid-1; 
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n;ll l,x,y;cin>>n>>l>>x>>y;
  	for(int i=0;i<n;i++)cin>>a[i];
  	//if(chck(x) && chck(y)){cout<<"0\n";return 0;}
  	int x_exist=chck(x,n);
  	int y_exist=chck(y,n);
  	for(int i=0;i<n;i++){
  		x_exist|=chck(a[i]-x,n);
  		y_exist|=chck(a[i]-y,n);
  	}
  	if(x_exist && y_exist){cout<<"0\n";return 0;}
  	else if(x_exist || y_exist){cout<<"1\n";
  		if(x_exist){cout<<y<<"\n";}
  		else cout<<x<<"\n";
  		return 0;
  	}
  	for(int i=0;i<n;i++){
  		y_exist=0;
  		ll z1=x+a[i];
  		ll z2=a[i]-x;
  		if(z1<=l)
  		y_exist=(chck(y+z1,n)|chck(z1-y,n));
  		if(y_exist){cout<<"1\n"<<z1<<"\n";exit(0);}
  		if(a[i]>x){
  			y_exist=(chck(a[i]-x+y,n)|chck(a[i]-x-y,n));
  		}
  		if(y_exist){cout<<"1\n"<<z2<<"\n";exit(0);}
  	}
  	cout<<"2\n"<<x<<" "<<y<<"\n";
  	return 0;

 }