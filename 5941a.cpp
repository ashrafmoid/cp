#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100004];
int main(){
	ll n,m;cin>>n>>m;
	ll mod=1e9+7;
	f[0]=f[1]=1;
	for(int i=2;i<=max(n,m);i++){f[i]=f[i-1]+f[i-2];f[i]%=mod;}
	ll ans=(2ll*(f[n]+f[m]-1ll +mod))%mod;
	cout<<ans<<"\n";
	return 0;
}