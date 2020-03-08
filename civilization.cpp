#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
vector<int> adj[300005];
int dimtr[300005];
int root[300005];
int cmp[300005];
int vis[300005];
void bfs(int node,int cmp){
	root[node]=cmp;
	queue<pair<pair<int,int>,int> > qt;
	qt.push(mp(mp(0,node),node));
	int last1=node;
	int  dis=0;
	while(!qt.empty()){
		pair<pair<int,int> ,int > x=qt.front();qt.pop();
		pair<int,int> u=x.f;
		int prnt=x.s;
		vis[u.s]=1;
		root[u.s]=cmp;
		for(int i=0;i<adj[u.s].size();i++){
			if(adj[u.s][i]==prnt)continue;
			qt.push(mp(mp(u.f+1,adj[u.s][i]),u.s));
		}
		last1=u.s;
	}
	if(last1==node) {dimtr[cmp]=0;return ;}
	qt.push(mp(mp(0,last1),last1));
	while(!qt.empty()){
		pair<pair<int,int> ,int > x=qt.front();qt.pop();
		pair<int,int> u=x.f;
		int prnt=x.s;
		for(int i=0;i<adj[u.s].size();i++){
			if(adj[u.s][i]==prnt)continue;
			qt.push(mp(mp(u.f+1,adj[u.s][i]),u.s));
		}
		if(dis<u.f){dis=u.f;}
	}
	dimtr[cmp]=dis;
	return ;
}
int find_root(int x){
	while(x!=cmp[x]){
		x=cmp[cmp[x]];
	}
	return x;
}
int main(){
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int n,m,q;cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		adj[a].pb(b);adj[b].pb(a);
	}
	for(int i=1;i<=n;i++){root[i]=i;cmp[i]=i;}
	int k=1;
	for(int i=1;i<=n;i++){
		//if(vis[i])continue;
		if(root[i]!=i)continue;
		bfs(i,k++);
	}
	for(int i=0;i<q;i++){
		int op,x,y;
		cin>>op>>x;
		if(op==1){
			int y=find_root(root[x]);
			//cout<<"y="<<y<<"\n";
			cout<<dimtr[y]<<"\n";
		}
		else{
			cin>>y;
			int r1=find_root(root[x]);
			int r2=find_root(root[y]);
			if(r1>r2)swap(r1,r2);
			if(r1!=r2){
				dimtr[r1]=max(max(dimtr[r1],dimtr[r2]),(dimtr[r1]+1)/2+(dimtr[r2]+1)/2+1);
				cmp[r2]=cmp[r1];
			}
			//else{cout<<dimtr[r1]<<"\n";}
		}
	}
	return 0;
}