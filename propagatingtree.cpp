	#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int a[200005];
vector<int> adj[200005];
int lvl[200005],st[200005],ft[200005];
int tmp;
int c[2][200005];
int n,m;
void dfs(int node ,int l,int prnt){
	st[node]=++tmp;
	lvl[node]=l;
	for(int i=0;i<adj[node].size();i++){
		if(adj[node][i]==prnt)continue;
		dfs(adj[node][i],l+1,node);
	}
	ft[node]=tmp;
	return ;
}
void add(int t,int x,int v){
	for(;x<=n;x+=x&-x){
		c[t][x]+=v;
	}
	return ;
}
int query(int t,int x){
	int ans=0;
	for(;x>0;x-=x&-x){
		ans+=c[t][x];
	}
	return ans;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		adj[x].pb(y);adj[y].pb(x);
	}
	dfs(1,0,0);
	for(int i=0;i<m;i++){
		int opt,x,val;
		cin>>opt>>x;
		if(opt==1){
			cin>>val;
			add(lvl[x]&1,st[x],val);add(lvl[x]&1,ft[x]+1,-val);
			add(!(lvl[x]&1),st[x],-val);add(!(lvl[x]&1),ft[x]+1,val);
		}
		else{
			cout<<(a[x]+query(lvl[x]&1,st[x]))<<"\n";
		}
	}
	return 0;
}