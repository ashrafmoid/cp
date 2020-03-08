#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int a[105],b[105],diff[105];
	diff[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){cin>>b[i];diff[i]=a[i]-k*b[i];}
	int m=100*n;
	int dp[105][10002];
	for(int i=0;i<=n;i++)for(int j=0;j<10002;j++)dp[i][j]=-10000;
	dp[0][m]=0;
	for(int i=1;i<=n;i++){
		for(int j=2*m;j>=0;j--){
			//dp[i][j]=-10000;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-diff[i]]+a[i]);
		}
	}
	if(dp[n][m]<=0)cout<<"-1\n";
	else cout<<dp[n][m]<<"\n";
	return 0;
}