#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300005][9];
int a1,a2;
bool can(ll mid,int m,int n){
	//map<ll,int>mp;
	vector<int>mp((1<<m),-1);
	for(int i=0;i<n;i++){
		ll tmp=0;
		for(int j=0;j<m;j++){
			if(a[i][j]>=mid)tmp|=(1<<j);
		}
		mp[tmp]=i+1;
	}
	if(mp[(1<<m)-1]!=-1){
		a1=a2=mp[(1<<m)-1];
		return true;
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<(1<<m);j++){
			if(mp[i]!=-1 && mp[j]!=-1 && (i|j)==(1<<m)-1){
				a1=mp[i];a2=mp[j];return true;
			}
		}
	}
	return false;
}
int main(){
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	ll lo=0,hi=1e14;
	ll ans=0;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		if(can(mid,m,n)){
			lo=mid+1;
		}
		else hi=mid-1;
	}
	cout<<a1<<" "<<a2<<"\n";
	return 0;
}