#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int t;cin>>t;
	unordered_map<int,int> vis;
	unordered_map<int,int>mp;
	int maxx;
	while(t--){
		int n;cin>>n;
		vis.clear();mp.clear();maxx=0;
		for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]++;maxx=max(maxx,a[i]);}
			int ans=0;
		for(int i=n-1;i>=0;i--){
			if(vis.find(a[i])!=vis.end()){
				mp[a[i]]--;
				continue;
			}
			mp[a[i]]--;
			vis[a[i]]=1;
			int tmp=0;
			for(int j=a[i];j<=maxx;j+=a[i]){
				if(mp.find(j)!=mp.end())tmp+=mp[j];
			}
			ans=max(ans,tmp);
			//if(mp[a[i]]==0)mp.erase(a[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}