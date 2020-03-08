#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;cin>>n>>k;
	ll a[100005],b[100005];
	ll ans=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	ll lo=1,hi=2e9;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		ll tmp=k;
		for(int i=0;i<n;i++){
			//cout<<" pr= "<<(mid*a[i])<<"\n";
			ll val=mid*a[i]-b[i];
			if(val<=0)continue;
			tmp-=val;
			if(tmp<0)break;
		}
		if(tmp<0){
			hi=mid-1;
		}
		else{
			//cout<<"mid= "<<mid<<"\n";	
			ans=mid;lo=mid+1;
		}
	}
	cout<<ans<<"\n";	
	return 0;
}