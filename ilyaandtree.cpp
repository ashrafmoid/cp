#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int a[200005];
vector<int> adj[200005];
int ans[200005];
void dfs(int node,int prnt,int g,int chck){
	int v=__gcd(g,a[node]);
	if(!chck)v=max(g,v);
	ans[node]=max(v,ans[node]);
	//cout<<"node= "<<node<<" ans= "<<v<<"\n";
	for(int i=0;i<adj[node].size();i++){
		if(prnt==adj[node][i])continue;
		if(!chck){
			dfs(adj[node][i],node,g,!chck);
		}
		dfs(adj[node][i],node,__gcd(g,a[node]),chck);
	}
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;adj[x].push_back(y);
		adj[y].push_back(x);
	}
	//cout<<"Yes\n";
	dfs(1,1,0,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}