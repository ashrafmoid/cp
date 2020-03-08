#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5002][5002];
ll mod=1e9+7;
int main(){
	string s,t;cin>>s>>t;
	int n=s.size();int m=t.size();
	//dp[n][m]=1ll;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			dp[i][j]=dp[i][j+1];
			if(s[i]==t[j])dp[i][j]+=dp[i+1][j+1]+1ll;
			if(dp[i][j]>=mod)dp[i][j]%=mod;
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){ans+=dp[i][0];
		if(ans>=mod)ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}