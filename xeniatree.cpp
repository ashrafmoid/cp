#include<bits/stdc++.h>
using namespace std;
const int LOGN=20,N=100005;
set<int> g[N];
int DP[LOGN][N],level[N],sub[N],par[N];
int ans[N];
int n,m;
int INF=int(1e9);
void dfs0(int u)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=DP[0][u])
		{
			DP[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;
	DP[0][0]=0;
	dfs0(0);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b=DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	par[centroid]=p;
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
	g[centroid].clear();
}
void update(int root){
	int x=root;
	ans[root]=min(ans[root],dist(x,root));
	while(1){
		ans[x]=min(ans[x],dist(x,root));
		if(x==par[x])break;
		x=par[x];
	}
	return ;
}
int query(int root){
	int res=INF;
	int x=root;
	while(1){
		res=min(res,ans[x]+dist(x,root));
		if(x==par[x])break;
		x=par[x];
	}
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		g[a-1].insert(b-1);
		g[b-1].insert(a-1);
	}
	preprocess();
	decompose(0,-1);
	for(int i=0;i<n;i++)ans[i]=INF;
		update(0);
	for(int i=0;i<m;i++){
		int t,v;cin>>t>>v;
		if(t==1)update(v-1);
		else cout<<query(v-1)<<"\n";
	}
	return 0;
}