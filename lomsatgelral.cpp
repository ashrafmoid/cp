#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
//#define mp make_pair
#define pb push_back
map<int,ll> mp[100005];
vector<int> adj[100005];
int col[100005];
ll ans[100005];
ll mx[100005];
void dfs(int root,int prnt){
	mp[root][col[root]]++;
	for(auto x:adj[root]){
		if(x==prnt)continue;
		dfs(x,root);
		if(mp[x].size()>mp[root].size()){mp[x].swap(mp[root]);ans[root]=ans[x];mx[root]=mx[x];}
		for(auto it : mp[x]){
			int v= mp[root][it.f] +=it.s;
			if(v>mx[root]){mx[root]=v;ans[root]=it.f;}
			else if(v==mx[root]){ans[root]+=it.f;}			
		}
		mp[x].clear();
	}
	//	cout<<"root= "<<root<<"mx= "<<mx[root]<<"ans= "<<ans[root]<<"\n";
	 return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++){cin>>col[i];ans[i]=col[i];mx[i]=1;}
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);adj[y].pb(x);
	}
	dfs(1,1);
	for(int i=1	;i<=n;i++)cout<<ans[i]<<" ";
	return 0;

}
