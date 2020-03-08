#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005];
ll mod=1e6+3;
int main(){
	int n;cin>>n;
	ll res=1;
	for(int i=0;i<n-1;i++){
		res*=3ll;
		if(res>=mod)res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}