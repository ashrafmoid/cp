#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF=1e14;
ll c[100005];
int n;
string s[100005];
//ll dp[100005];
map<pair<ll,string>,ll>mp;
ll get_ans(int indx,string prv){
	if(indx==n)return 0;
	ll tmp=INF;
	if(mp.find(make_pair(indx,prv))!=mp.end())return mp[make_pair(indx,prv)];
	//if(dp[indx]!=-1)return dp[indx];
	if(s[indx]>=prv)tmp=get_ans(indx+1,s[indx]);
	reverse(s[indx].begin(),s[indx].end());
	if(s[indx]>=prv)
	tmp=min(tmp,c[indx]+get_ans(indx+1,s[indx]));
	reverse(s[indx].begin(),s[indx].end());
	mp[make_pair(indx,prv)]=tmp;
	return tmp;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){cin>>c[i];}
	for(int i=0;i<n;i++)cin>>s[i];
	ll ans=get_ans(0,"");
	if(ans>=INF){cout<<-1<<"\n";}
	else cout<<ans<<"\n";
	return 0;
}