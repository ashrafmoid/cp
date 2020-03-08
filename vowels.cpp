#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[(1ll<<24)];
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int n;cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		ll tmp=0;
		for(int j=0;j<3;j++)tmp|=(1ll<<(s[j]-'a'));f[tmp]++;
	}
	ll ans=0;
	for(int i=0;i<24;i++){
		for(ll mask=0;mask<(1ll<<24);mask++){
			if(mask&(1ll<<i))f[mask]+=f[mask^(1ll<<i)];
		}
	}
	for(ll mask=0;mask<(1ll<<24);mask++){
		//ll tmp=mask;
		//int cnt_bits=0;
		//while(tmp){cnt_bits++;tmp/=2;}
		ll tmp=(1ll*n-f[(1ll<<24)-1-mask]);
		ans^=(tmp*tmp);
	}
	cout<<ans<<"\n";
	return 0;
}	