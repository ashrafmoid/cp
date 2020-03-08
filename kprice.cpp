#include<bits/stdc++.h>
using namespace std;
int a[200005];
//int dp[10005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		int n,p,k;cin>>n>>p>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		//memset(dp,0,sizeof(dp));
		int pref=0,ans=0;
		for(int i=1;i<=k+1;i++){
			int sum=pref;
			if(sum>p)break;
			int cnt=i-1;
			for(int j=i+k-1;j<=n;j+=k){
				if(sum+a[j]<=p){
					cnt+=k;
					sum+=a[j];
				}
				else break;
			}
			pref+=a[i];
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";
	}
	return 0;

}