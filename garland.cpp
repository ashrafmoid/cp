#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
vector<int> adj[1000002];
int t[1000002];
ll ans[1000002];
ll sum=0;
int root1;
//int st[1000002],ft[1000002];
//int tim=0;
int ans1=-1,ans2=-1;
void dfs(int root,int prnt){
	//st[root]=tim++;
	ans[root]=1ll*t[root];
	for(auto x:adj[root]){
		if(x==prnt)continue;
		dfs(x,root);
		ans[root]+=ans[x];
	}
	if(root !=root1 && ans[root]==sum/3){
		if(ans1==-1){ans1=root;ans[root]=0;}
		else if(ans2==-1){ans2=root;ans[root]=0;}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p>>t[i];
		sum+=1ll*t[i];
		if(p==0){root1 = i;continue;}
		//adj[i].pb(p);
		adj[p].pb(i);
	}
	if(sum%3){cout<<"-1\n";return 0;}
	dfs(root1,0);
	/*int ans1=-1,ans2=-1;
	for(int i=1;i<=n;i++){
		if(i==root)continue;
		if(ans[i]==sum/3){ans1=i;break;}
	}
	for(int i=1;i<=n;i++){
		if(i==root || i==ans1)continue;
		else if((st[ans1]<=st[i] && ft[ans1]>=ft[i]))continue;
		else if((st[i]<=st[ans1] && ft[i]>=ft[ans1]) && ans[i]== 2ll*sum/3){ans2=i;break;}
		else if(ans[i]==sum/3){ans2=i;break;}
	}
	if(ans1==-1 || ans2==-1){cout<<"-1\n";return 0;}
	*/
	if(ans1==-1 || ans2==-1){cout<<"-1\n";return 0;}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}