#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[100001];
vector<int>adj[100001];
int vis[100001];
ll ans;
bool cmp(pair<int,int>p1,pair<int,int> p2){
	return p1.second*p2.first < p1.first*p2.second;
}
pair<ll,ll> dfs(int root,int prnt){
	vis[root]=1;
	ll zeros=w[root]==0?1ll:0ll;
	ll ones=w[root]==1?1ll:0ll;
	vector<pair<ll,ll> >v;
	for(int i=0;i<adj[root].size();i++){
		if(vis[adj[root][i]] || prnt==adj[root][i])continue;
		v.push_back(dfs(adj[root][i],root));
	}
	if(v.size()!=0){
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<v.size();i++){
			ans+=ones*v[i].first;
			ones+=v[i].second;
			zeros+=v[i].first;
		}
		v.clear();
	}
	return make_pair(zeros,ones);
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;ans=0;
		for(int i=1;i<=n;i++){cin>>w[i];adj[i].clear();vis[i]=0;}
		for(int i=0;i<n-1;i++){
			int u,v;cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1,1);
		cout<<ans<<"\n";
	}
	return 0;
}