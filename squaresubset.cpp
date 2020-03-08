#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[75];
const int lmt=1<<20;
int b[75];
int vis[75];
ll mod=1e9+7;
ll pwr[100005];
ll dp[2][lmt];
int main(){
	vector<int> prms;
	for(int i=2;i<=70;i++){
		if(vis[i])continue;
		prms.push_back(i);
		for(int j=i;j<=70;j+=i)vis[j]=1;
	}
	for(int i=2;i<=70;i++){
		int tmp=0;
		int x=i;
		for(int j=0;j<prms.size();j++){
			while(x%prms[j]==0){
				x/=prms[j];tmp^=(1<<j);
			}
			if(x==1)break;
		}
		b[i]=tmp;
	}
	int n;cin>>n;
	pwr[0]=1;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[x]++;
		pwr[i]=2ll*pwr[i-1];
		if(pwr[i]>=mod)pwr[i]%=mod;
	}
	dp[0][0]=1;
	for(int i=1;i<=70;i++){
		for(int j=0;j<lmt;j++){
			if(a[i]!=0){
			dp[i&1][j^b[i]]+=(dp[(i-1)&1][j]*(pwr[a[i]-1])%mod);
			if(dp[i&1][j^b[i]]>=mod)dp[i&1][j^b[i]]%=mod;
			dp[i&1][j]+=(dp[(i-1)&1][j]*(pwr[a[i]-1])%mod);
			if(dp[i&1][j]>=mod)dp[i&1][j]%=mod;
			}
			else{
				dp[i&1][j]=dp[(i-1)&1][j];
			}
		}
		for(ll mask=0;mask<lmt;mask++)dp[(i-1)&1][mask]=0;
	}
	cout<<(dp[70 & 1][0]-1+mod)%mod<<"\n";
	return 0;
}