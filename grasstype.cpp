#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
unordered_map<int,int>mp[100005];
vector<int>adj[100005];
ll a[100005];
ll ans[100005];
void dfs(int root,int prnt){
	mp[root][a[root]]++;
	for(auto x:adj[root]){
		if(x==prnt )continue;
		dfs(x,root);
		if(mp[x].size()>mp[root].size()){
			mp[x].swap(mp[root]);
		}
		for(auto it:mp[x]){
			if(a[root]%(it.f))continue;
			else if(mp[root].find(a[root]/(it.f))!=mp[root].end()){
				ans[root]+=mp[root][a[root]/it.f]*(it.s);
			}
		}
		for(auto it :mp[x]){
			mp[root][it.f]+=it.s;
		}
	}
	//cout<<"root "<<root<<"ans= "<<ans[root]<<"\n";
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);adj[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=1ll*ans[i];
		cout<<sum<<"\n";
	return 0;

}