#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main(){
	string s;cin>>s;
	int len=s.size()-1;
	ll ans=0;
	ll bs=0;
	for(int i=len;i>=0;i--){
		if(s[i]=='b')bs++;
		if(bs>=mod)bs%=mod;
		if(s[i]=='a'){ans+=bs;bs=bs*2ll;
			if(bs>=mod)bs%=mod;
			if(ans>=mod)ans%=mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}