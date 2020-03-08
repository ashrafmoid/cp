#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300004];
ll dp[300004];
int main(){
	int n,m,k;cin>>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ll sum=a[i];
		for(int j=i-1;j>=0&&i-j<=m;j--){
			dp[i]=max(dp[i],dp[j]+sum-k);
			sum+=a[j];
		}
		ans=max(ans,dp[i]);
		//dp[i]=max(0,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;

}