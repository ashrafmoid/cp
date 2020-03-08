#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct p{
	ll x,y,z;
}point;
int main(){
	int n;cin>>n;
	point p1 [50004];
	int vis[50004];
	for(int i=0;i<n;i++){
		vis[i]=0;
		ll a,b,c;cin>>a>>b>>c;
		p1[i].x=a;p1[i].y=b;p1[i].z=c;
	}
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ll dis=1e18;int indx=i;
		for(int j=i+1;j<n;j++){
			if(vis[j])continue;
			ll tmp=(p1[i].x-p1[j].x)*(p1[i].x-p1[j].x)+(p1[i].y-p1[j].y)*(p1[i].y-p1[j].y)+(p1[i].z-p1[j].z)*(p1[i].z-p1[j].z);
			if(tmp<dis){dis=tmp;indx=j;}
		}
		cout<<i+1<<" "<<indx+1<<"\n";
		vis[indx]=1;
	}
	return 0;
}