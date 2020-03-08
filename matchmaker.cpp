#include<bits/stdc++.h>
using namespace std;
int dp[2][1001][1001];
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		dp[0][b][a]++;
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		dp[1][b][a]++;
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=1000;i++){
		int tmp1=0,tmp2=0;
		for(int j=1;j<=1000;j++){
			tmp1+=dp[0][i][j];
			tmp2+=dp[1][i][j];
			ans2+=min(dp[0][i][j],dp[1][i][j]);
		}
		ans1+=min(tmp1,tmp2);
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}