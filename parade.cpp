#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[30008];
int main(){
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>c[i];
		ll lo=1,hi=1e17;
		ll ans=0;
		while(lo<=hi){
			ll mid=(lo+hi)/2;
			ll res=0;
			ll tmp=0;
			for(int i=1;i<=n;i++){
				ll x=res+c[i];
				if(x<mid)x=c[i];
				tmp+=x/mid;
				res=x%mid;
			}
			if(tmp>=k){ans=mid;lo=mid+1ll;}
			else hi=mid-1ll;
		}
		cout<<k*ans<<"\n";
	}
	return 0;
}