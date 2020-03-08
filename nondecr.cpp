#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[65][10];
int main(){
	int p;cin>>p;
	for(int i=0;i<10;i++)dp[1][i]=1;
	for(int i=2;i<=64;i++){
		for(int x=0;x<10;x++){
			for(int j=x;j<10;j++)dp[i][j]+=dp[i-1][x];
		}
	}
	while(p--){
		int op,n;cin>>op>>n;
		ll ans=0;
		for(int i=0;i<10;i++)ans+=dp[n][i];
		cout<<op<<" "<<ans<<"\n";
	}
	return 0;
}