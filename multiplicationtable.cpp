#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll lo=1,hi=n*m;
	ll ans=1;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		ll tmp=0;
		for(int i=1;i<=n;i++){
			tmp+=min((mid-1)/i,m);
		}
		if(tmp<k){ans=mid;lo=mid+1;}
		else hi=mid-1;
	}
	cout<<ans<<"\n";
	return 0;

}