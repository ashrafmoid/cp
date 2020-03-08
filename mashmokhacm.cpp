#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2002][2002];
ll mod=1e9+7;
int n;
ll f(int num,int indx){
	if(indx==0){
		return 1ll*(num<=n);
	}
	if(num>n)return 0;
	if(dp[num][indx]!=-1)return dp[num][indx];
	ll res=0;
	for(int i=1;i<=(n/num);i++){
		res+=f(num*i,indx-1);
		if(res>=mod)res%=mod;
	}
	dp[num][indx]=res;
	return res;
}
int main(){
	int k;cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<f(1,k)<<"\n";
	return 0;
}