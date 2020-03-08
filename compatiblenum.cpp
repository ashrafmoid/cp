#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001];
ll dp[4194308];
int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	int n;cin>>n;
	int maxx_bits=0;ll maxx=0;
	for(int i=0;i<n;i++){cin>>a[i];dp[a[i]]=a[i];maxx=max(maxx,a[i]);}
	while(maxx){maxx_bits++;maxx/=2;}
	for(int i=0;i<22;i++){
		for(int mask=0;mask<(1<<22);mask++)if((1<<i)&mask)dp[mask]=max(dp[mask^(1<<i)],dp[mask]);
	}
	for(int i=0;i<n;i++){
		ll cmplmnt=(1<<maxx_bits)-1-a[i];
		if(dp[cmplmnt])cout<<dp[cmplmnt]<<" ";
		else cout<<"-1 ";
	}
	return 0;
}