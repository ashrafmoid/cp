#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef long long ll;
char s[5005][2];
ll dp[5005];
ll mod=1e9+7;
int main(){
	int n;cin>>n;
	dp[0]=1;
	int tot=0;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		if(s[i][0]=='f')tot++;
		else{
			for(int j=1;j<=tot;j++){
				dp[j]=(dp[j]+dp[j-1]);
				if(dp[j]>=mod)dp[j]-=mod;
			}
		}
	}
	cout<<dp[tot]<<"\n";
	return 0;
}