#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][2000];
ll ncr[1007][1007];
ll mod=1e9+7;
int main(){
	int n,m;cin>>n>>m;
	//for(int i=0;i<=n;i++){ncr[i][i]=1;ncr[i][0]=1;}
	//for(int i=1;i<=n;i++)for(int j=1;j<=10 && j<=i;j++){ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];ncr[i][j]%=mod;}
	for(int i=1;i<=n;i++)dp[1][i]=i;
	for(int len=2;len<=2*m;len++){
		for(int i=1;i<=n;i++){dp[len][i]+=dp[len-1][i]+dp[len][i-1];if(dp[len][i]>=mod)dp[len][i]%=mod;\
			cout<<"len= "<<len<<" i= "<<i<<" dp= "<<dp[len][i]<<"\n";
			} 
	}
	ll ans=0;
	//cout<<ncr[n][m]<<"\n";
	for(int i=1;i<=n;i++){ans+=dp[2*m][i];if(ans>=mod)ans%=mod;}
	// /ans*=ncr[n][m];
	//if(ans>=mod)ans%=mod;
	cout<<ans<<"\n";
	return 0;
}