#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
//#define SYN ios_base::sync_with_stdio(false),cin.tie(NULL)
ll d[2005][2005];
vector<int > adj[2005];
vector<pair<int,int> >edg;
int pa[2005];
int root(int x){
	return pa[x] = (pa[x] == x ? x : root(pa[x]));
}
void unin(int r1,int r2){
	int p1=root(r1);
	int p2=root(r2);
	pa[p1]=p2;
	return ;
}
bool vld(int n){
	bool flg=false;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j && d[i][j]!=0){return true;}
			if(d[i][j]!=d[j][i]){return true;}
			if(i!=j && (d[i][j]==0 || d[j][i]==0)){return true;}
		}
	}
	return flg;
}
bool cmp(pair<int,int> p1,pair<int,int> p2){
	return d[p1.f][p1.s]<d[p2.f][p2.s];
}
//queue<pair <int,int> > q;
//int vis[2005];
void dfs(int pos,int src,ll w,int p){
	//int dis=0;
	if(w!=d[pos][src] || w!=d[src][pos]){cout<<"NO\n";exit(0);}
	for(auto it: adj[pos]){
		if(it==p)continue;
		dfs(it,src,w+d[pos][it],pos);
	}
	return ;
}
int main(){
	//SYN;
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	int flg=0;
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cin>>d[i][j];if((i!=j && d[i][j]==0) ||(i==j && d[i][j]!=0 )){flg=1;}if(i>j)edg.pb(mp(i,j));}pa[i]=i;}//st.insert(mp(d[i][j],mp(i,j)));}
	if(flg){cout<<"NO\n";return 0;}
	sort(edg.begin(),edg.end(),[&](pair<int,int> p1,pair<int,int> p2){return d[p1.first][p1.second] < d[p2.first][p2.second];});
	//if(vld(n)){cout<<"NO\n";return 0;}
	//cout<<"hmm\n";
	for(auto it: edg){
		int r1=root(it.f);
		int r2=root(it.s);
		if(r1==r2)continue;
		//unin(r1,r2);
		adj[it.f].pb(it.s);adj[it.s].pb(it.f);
		pa[r1]=r2;
	}
	//cout<<"acha\n";
	for(int i=1;i<=n;i++){
		//memset(vis,0,sizeof(vis));
		//for(int i=1;i<=n;i++)vis[i]=0;
		dfs(i,i,0,-1);
	}
	cout<<"YES\n";
	return 0;
	
}	