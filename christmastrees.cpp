#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	deque<pair<ll,ll> > dq;
	vector<ll> ans;
	map<ll,int>mp;
	for(int i=0;i<n;i++){
		dq.push_back(make_pair(a[i],1ll));
		mp[a[i]]=1;
	}
	ll cnt=0;
	ll res=0;
	while(cnt<m){
		pair<ll,ll>p=dq.front();
		dq.pop_front();
		if(mp.find(p.first+p.second)!=mp.end() && mp.find(p.first-p.second)!=mp.end())continue;
		if(mp.find(p.first+p.second)==mp.end()){ans.push_back(p.first+p.second);cnt++;mp[p.first+p.second]=1;res+=p.second;}
		if(cnt>=m)break;
		if(mp.find(p.first-p.second)==mp.end()){ans.push_back(p.first-p.second);cnt++;mp[p.first-p.second]=1;res+=p.second;}
		dq.push_back(make_pair(p.first,p.second+1));
	}
	cout<<res<<"\n";
	for(int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}