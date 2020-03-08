#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100002];
ll pre[100002],suf[100002];
int main(){
	ll n,k;cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++)pre[i]=a[i-1]+pre[i-1];
	for(int i=n;i>0;i--)suf[i]=a[i-1]+suf[i+1];
	ll lo=0,hi=1e10;
	ll ans=a[n-1]-a[0];
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		ll tmp=k+1;
		for(int i=0;i<n;i++){
			ll cnt=(1ll*i+1)*a[i]-pre[i+1];
			int pos=lower_bound(a,a+n,a[i]+mid)-a;
			cnt+=suf[pos+1]-(n-1ll*pos)*(a[i]+mid);
			//if(cnt<0){cout<<"mid= "<<mid<<" i= "<<i<<"pre\n";}
			tmp=min(tmp,cnt);
			cnt=suf[i+1]-(n-1ll*i)*a[i];
			pos=lower_bound(a,a+n,a[i]-mid)-a;
			cnt+=1ll*pos*(a[i]-mid)-pre[pos];
			//if(cnt<0){cout<<"mid= "<<mid<<" i= "<<i<<"suf\n";}
			tmp=min(tmp,cnt);
			//cout<<"tmp= "<<tmp
		}
		//cout<<"mid= "<<mid<<" tmp= "<<tmp<<"\n";
		if(tmp>k)lo=mid+1;
		else {ans=mid;hi=mid-1;}
	}
	cout<<ans<<"\n";
	return 0;
}