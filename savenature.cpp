#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200002];

bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		p[0]=0;
		for(int i=1;i<=n;i++){cin>>p[i];}
		sort(p+1,p+n+1,cmp);
		int x,a;cin>>x>>a;
		int y,b;cin>>y>>b;
		if(x<y){
			swap(x,y);swap(a,b);
		}
		ll k;cin>>k;
		int lcm=min((1ll*a*b)/__gcd(a,b),1ll*(n+1));
		for(int i=1;i<=n;i++)p[i]+=p[i-1];
		int lo=1,hi=n,ans=-1;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			//cout<<"mid= "<<mid;
			int l=mid/lcm;
			int r=mid/a-l;
			int theta=mid/b-l;
			//cout<<"l= "<<l<<"r= "<<r<<"theta= "<<theta<<"\n";
			ll tmp=1ll*x*p[l+r]/100;
			//cout<<"tmp= "<<tmp;
			tmp+=1ll*y*(p[l+r+theta]-(p[r+l]-p[l]))/100;
			//tmp/=100;
			//cout<<"tmp= "<<tmp<<"\n";
			if(tmp>=k){ans=mid;hi=mid-1;}
			else lo=mid+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}