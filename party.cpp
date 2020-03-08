#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
vector<int>adj[2005];
int p[2005];
int dfs(int root ,int prnt){
	int mx=1;
	for(int i=0;i<adj[root].size();i++){
		if(adj[root][i]==prnt)continue;
		mx=max(mx,1+dfs(adj[root][i],root));
	}
	return mx;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==-1)continue;
		adj[i].pb(p[i]);adj[p[i]].pb(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(p[i]!=-1)continue;
		ans=max(ans,dfs(i,-1));
	}
	cout<<ans<<"\n";
	return 0;
}