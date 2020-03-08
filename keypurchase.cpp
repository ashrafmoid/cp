#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cst[30][30];
ll dp[(1<<20)];
int f[30];
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	ll n,m;cin>>n>>m;
	string s;cin>>s;
	memset(cst,0,sizeof(cst));
	memset(f,0,sizeof(f));
	f[s[0]-'a']++;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1])continue;
		f[s[i]-'a']++;
		int u=s[i]-'a';
		int v=s[i-1]-'a';
		//if(u>v)swap(u,v);
		cst[u][v]++;
		cst[v][u]++;
		//cst[v][u]=cst[u][v];
	}
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<"i= "<<i<<" j= "<<j<<" cst= "<<cst[i][j]<<"\n";
	// 	}
	// }
	for(int mask=1;mask<(1<<m);mask++){
		dp[mask]=1e16;
		int val=__builtin_popcount(mask);
		for(int i=0;i<m;i++){
			if(((1<<i)&mask) == 0)continue;
			ll res=mask^(1<<i);
			ll tmp=0;
			for(int j=0;j<m;j++){
				// if(res==0){
				// 	tmp-=cst[i][j];continue;
				// }
				if((1<<j)&mask)tmp+=cst[i][j]*1ll*val;
				else tmp-=cst[i][j]*1ll*val;
			}
			//if(mask==2)cout<<"tmp= "<<tmp<<"\n";
			dp[mask]=min(dp[mask],dp[res]+tmp);
		}
		//cout<<"mask= "<<mask<<" dp= "<<dp[mask]<<"\n";
	}
	cout<<dp[(1<<m)-1]<<"\n";
	return 0;
}