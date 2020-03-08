#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll ans_lo[100005];
ll ans_hi[100005];
int main(){
	int n,m;cin>>n>>m;
	map<int,int> mp;
	for(int i=1;i<=n;i++){a[i]=i;mp[a[i]]=i;ans_lo[i]=i;ans_hi[i]=i;}
	for(int i=0;i<m;i++){
		ll x;cin>>x;
		ll pos=mp[x];
		if(pos==1)continue;
		ll tmp=a[pos-1];
		a[pos-1]=x;
		a[pos]=tmp;
		ans_lo[x]=min(ans_lo[x],pos-1);
		ans_hi[tmp]=max(ans_hi[tmp],pos);
		mp[x]=pos-1;
		mp[tmp]=pos;
	}
	for(int i=1;i<=n;i++){
		cout<<ans_lo[i]<<" "<<ans_hi[i]<<"\n";
	}
	return 0;
}