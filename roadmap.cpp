#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
vector<int> adj[50002];
int prnt[50004];
void dfs(int root,int p){
	prnt[root]=p;
	for(auto x:adj[root]){
		if(x==p)continue;
		dfs(x,root);
	}
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,r1,r2;cin>>n>>r1>>r2;
	for(int i=1;i<=n;i++){
		if(i==r1)continue;
		int p;cin>>p;
		adj[i].pb(p);adj[p].pb(i);
	}
	dfs(r2,r2);
	for(int i=1;i<=n;i++){
		if(i==r2)continue;
		cout<<prnt[i]<<" ";
	}
	return 0;
}