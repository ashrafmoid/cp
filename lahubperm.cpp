#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int vis[2005];
ll dp[2005];
ll ncr[2005][2005];
ll fct[2005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fct[0]=1ll;ncr[0][0]=1ll;
	//for(int i=1;i<2005;i++)fct[i]=1ll*i*fct[i-1];
	for(int i=1;i<2005;i++){ncr[i][0]=1ll;ncr[i][i]=1ll;fct[i]=1ll*i*fct[i-1];
		if(fct[i]>=mod)fct[i]%=mod;
	}
	for(int i=1;i<2005;i++){
		for(int j=1;j<i;j++){
			ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
			if(ncr[i][j]>=mod)ncr[i][j]%=mod;
		}
	}
	int n;cin>>n;
	int a[2005];
	int tot=0,mtch=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==-1)tot++;
		else vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=-1)continue;
		if(vis[i]==0)mtch++;
	}
	//cout<<tot<<" "<<mtch<<"\n";
	//memset(dp,-1,sizeof(dp));
	//dp[2][]
	for(int i=mtch;i>=0;i--){
		dp[i]=ncr[mtch][i]*fct[tot-i];
		if(dp[i]>=mod)dp[i]%=mod;
		for(int j=i+1;j<=mtch;j++){
			dp[i]-=(ncr[j][i]*dp[j])%mod;
			while(dp[i]<0)dp[i]+=mod;
			if(dp[i]>=mod)dp[i]%=mod;
		}
		if(dp[i]>=mod)dp[i]%=mod;
	}
	cout<<dp[0]<<"\n";
	return 0;


}