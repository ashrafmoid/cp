#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[3][100001];
vector<int> adj[100001];
int ansclr[100001];
int ansflg=0;
ll ansval[100001];
ll dfs(int root,int p,int clr1,int clr2){
	ll res=c[clr1][root];
	//prnt[root]=p;
	//clrs[root]=clr;
	int child=0;
	ll tmp=1e15;
	for(int i=0;i<adj[root].size();i++){
		if(adj[root][i]==p)continue;
		child++;
		for(int k=0;k<3;k++){
			if(k==clr1 || k==clr2)continue;
			tmp=min(dfs(adj[root][i],root,k,clr1),tmp);
		}
	}
	if(child>1)ansflg=-1;
	if(child==0)tmp=0;
	if(ansval[root]<res+tmp){ansval[root]=res+tmp;ansclr[root]=clr1;}
	return res+tmp;

}
// void print(int root,int p,int clr1,int clr2){
// 	ansclr[root]=clr1;
// 	//prnt[root]=p;
// 	//clrs[root]=clr;
// 	ll tmp1=1e15,tmp2=1e15;
// 	for(int i=0;i<adj[root].size();i++){
// 		if(adj[root][i]==p)continue;
// 		for(int k=0;k<3;k++){
// 			if(k==clr1 || k==clr2)continue;
// 			if(tmp1==1e15)tmp1=dfs();
// 		}
// 	}
// 	return;
// }
int main(){
	int n;cin>>n;
	int root=-1;
	for(int i=0;i<3;i++)for(int j=0;j<n;j++)cin>>c[i][j];
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ansval[i]=1e15;
	}
	ansval[n-1]=1e15;
	for(int i=0;i<n;i++)if(adj[i].size()==1)root=i;
	if(root==-1){cout<<"-1\n";return 0;}
	ll ans=1e15;
	int flg=-1;
	for(int i=0;i<3;i++){
		if(ans>dfs(root,root,i,-1)){ans=dfs(root,root,i,-1);flg=i;}
	}
	if(flg==-1 || ansflg==-1){cout<<"-1\n";return 0;}
	//cout<<ans<<"\n";
	//print(root,root,flg,-1);
	ans=0;
	for(int i=0;i<n;i++)ans+=ansval[i];
		cout<<ans<<"\n";
	for(int i=0;i<n;i++)cout<<ansclr[i]+1<<" ";
	return 0;
}