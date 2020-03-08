#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
vector<int> adj[100005];
//int p[100005];
int dp[100005][20];
int st[100005],ft[100005];
int tim=0;
vector<int>h[100005];
int ht[100005];
void dfs(int root,int lvl){
	st[root]=tim;
	h[lvl].pb(tim);tim++;
	ht[root]=lvl;
	for(auto it:adj[root]){
		if(it==dp[root][0])continue;
		dfs(it,lvl+1);
	}
	ft[root]=tim;
	return ;
}
int get_root(int node,int p){
	int res=node;
	while(p){
		int x=p&-p;
		p-=x;int cnt=0;
		while(x){cnt++;x/=2;}cnt--;
		res=dp[res][cnt];
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		dp[i][0]=p;
		if(p!=0){adj[i].pb(p);adj[p].pb(i);}
	}
	int m;cin>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<20;j++)dp[i][j]=dp[dp[i][j-1]][j-1];
	}
	for(int i=1;i<=n;i++){
		if(dp[i][0]==0)dfs(i,0);
	}
	for(int i=0;i<m;i++){
		int v,p;cin>>v>>p;
		int root=get_root(v,p);
		if(root==0){cout<<"0 ";continue;}
		int l1=lower_bound(h[ht[root]+p].begin(),h[ht[root]+p].end(),st[root])-h[ht[root]+p].begin();
		int l2=upper_bound(h[ht[root]+p].begin(),h[ht[root]+p].end(),ft[root])-h[ht[root]+p].begin()-1;
		cout<<(l2-l1)<<" ";
	}
	return 0;

}