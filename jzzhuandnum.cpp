#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1048580];
ll pwr[1048580];
ll mod=1e9+7;
int main(){
	pwr[0]=1ll;
	for(int i=1;i<1048580;i++){
		pwr[i]=2ll*pwr[i-1];
		pwr[i]%=mod;
	}
	// for(int i=0;i<1048580;i++){
	// 	pwr[i]--;
	// 	pwr[i]+=mod;
	// 	pwr[i]%=mod;
	// }
	//ll mod=1e9+7;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;dp[x]++;
	}
	for(int i=0;i<20;i++)for(int mask=0;mask<(1<<20);mask++){
		if(mask&(1<<i))dp[mask^(1<<i)]+=dp[mask];
		dp[mask^(1<<i)]%=mod;
	}
	ll ans=0;
	for(int i=0;i<(1<<20);i++){
		if(__builtin_popcount(i)%2){
			ans-=pwr[dp[i]];
		}
		else ans+=pwr[dp[i]];
		if(ans<0)ans+=mod;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}