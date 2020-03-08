	#include<bits/stdc++.h>
	using namespace std;
	#define mp make_pair
	typedef long long ll;
	ll mod=1e9+7;
	//ll** dp;
	//ll dp[4][10000007];
	ll dp[4][2];
	int main(){
		
		int n;cin>>n;
		//memset(dp,-1,sizeof(dp));
		memset(dp,0,sizeof(dp));
		dp[0][0]=1ll;
		for(int i=1;i<=n;i++){
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					if(k==j)continue;
					dp[j][i&1]+=dp[k][(i-1)&1];
					if(dp[j][i&1]>=mod)dp[j][i&1]%=mod;
				}
			}
			for(int j=0;j<4;j++)dp[j][(i-1)&1]=0;
		}
	cout<<dp[0][n&1]<<"\n";
		return 0;
	}