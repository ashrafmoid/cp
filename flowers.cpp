#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005];
ll mod=1e9+7;
int main(){
	f[0]=1ll;
	int t,k;cin>>t>>k;
	for(int i=1;i<=100001;i++){
		f[i]=f[i-1];
		if(f[i]>=mod)f[i]%=mod;
		if(i-k>=0)f[i]+=f[i-k];
		if(f[i]>=mod)f[i]%=mod;
	}
	for(int i=1;i<=100001;i++){
		f[i]+=f[i-1];
		if(f[i]>=mod)f[i]%=mod;
	}
	for(int i=0;i<t;i++){
		int a,b;cin>>a>>b;
		ll res=(f[b]-f[a-1]+mod)%mod;
		cout<<res<<"\n";
	}
	return 0;
}