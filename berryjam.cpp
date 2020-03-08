#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<2*n;i++)cin>>a[i];
		map<int,int>mp;
		mp[0]=0;
		int cur=0;
		for(int i=n;i<2*n;i++){
			if(a[i]==1)cur++;
			else --cur;
			if(!mp.count(cur))mp[cur]=i-(n-1);
		}
		int dif=0;
		for(int i=0;i<2*n;i++){
			if(a[i]==1)dif++;
			else dif--;
		}
		 cur=0;
		int ans=2*n;
		for(int i=n-1;i>=0;i--){
			if(a[i]==1)cur++;
			else --cur;
			if(mp.count(dif-cur))
			ans=min(ans,n-i+mp[dif-cur]);
		}
		if(mp.count(dif))ans=min(ans,mp[dif]);
		cout<<ans<<"\n";
		mp.clear();
	}
	return 0;
}