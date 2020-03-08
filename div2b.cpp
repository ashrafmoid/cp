#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
string t;
//int dp[505][505];
int dp[505][1025];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;cin>>n>>m;
	int mat[505][505];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mat[i][j];
	for(int i=1;i<=n;i++){
		for(int j=0;j<1024;j++){
			for(int v=1;v<=m;v++){dp[i][j]=dp[i-1][j^mat[i][v]]|dp[i][j];if(dp[i][j])break;}
		}
	}	
	int flg=0;
	int ans;
	for(int i=1;i<=1023;i++)if(dp[n][i]){flg=1;ans=i;break;}
	if(flg==0){cout<<"NIE\n";return 0;}
	cout<<"TAK\n";
	//cout<<ans<<"\n";
	int res[505];
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++)if(dp[i-1][ans^mat[i][j]]){ans=ans^mat[i][j];res[i]=j;break;}
	}
	//for(int i=1;i<=m;i++)if(dp[1][ans]){res[1]=i;break;}
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	return 0;
}