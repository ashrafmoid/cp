#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[200002];
ll sz[200002];
ll dp[200002];
//int prnt[200002];
ll ans;
ll calcsize(int node,int p){
	//lvl[node]=l;
	//ans+=l;
	sz[node]=1;
	//prnt[node]=p;
	for(int i=0;i<adj[node].size();i++){
		if(adj[node][i]!=p){sz[node]+=calcsize(adj[node][i],node);
				//sz[node]+=sz[adj[node][i]];
			}
	}
	return sz[node];
}
ll calcdp(int node,int prnt){
	dp[node]=sz[node];
	for(int i=0;i<adj[node].size();i++){
		if(adj[node][i]==prnt)continue;
		dp[node]+=calcdp(adj[node][i],node);
		//dp[node]+=dp[adj[node][i]];
	}
	return dp[node];
}
void getans(int node,int prnt){
	ans=max(ans,dp[node]);
	for(int i=0;i<adj[node].size();i++){
		if(adj[node][i]==prnt)continue;
		int u=adj[node][i];
		dp[node]-=sz[u];
		dp[node]-=dp[u];
		sz[node]-=sz[u];
		sz[u]+=sz[node];
		dp[u]+=sz[node];
		dp[u]+=dp[node];
		getans(u,node);
		dp[u] -= dp[node];
		dp[u] -= sz[node];
		sz[u] -= sz[node];
		sz[node] += sz[u];
		dp[node] += sz[u];
		dp[node] += dp[u];
		//getans(u,node);
	}
	return ;
}
int main(){
	int n;cin>>n;

	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	calcsize(1,1);
	calcdp(1,1);
	//cout<<"ans= "<<ans<<"\n";
	getans(1,1);
	cout<<ans<<"\n";
	return 0;
}