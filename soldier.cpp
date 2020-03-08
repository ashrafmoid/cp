#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
ll mod=1e9+7;
ll dp[5000005];
char vis[5000005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(vis,'n',sizeof(char));
	for(int i=2;i<5000004;i++){
		if(vis[i]=='y')continue;
		for(int j=i;j<5000004;j+=i){
			int tmp=j;int cnt=0;
			while(tmp%i==0){tmp/=i;cnt++;}
			dp[j]+=cnt;vis[j]='y';
		}
	}
	for(int i=2;i<5000004;i++)dp[i]+=dp[i-1];
	int t;cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		cout<<(dp[a]-dp[b])<<"\n";
	}
	return 0;
}