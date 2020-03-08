#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
ll mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll l,r;cin>>l>>r;l--;
	ll odd=0,evn=0;
	int trn=1;
	ll tmp=1;
	while(l){
		if(trn%2){
			odd+=min(tmp,l);l-=min(tmp,l);tmp*=2ll;
			if(odd>=mod)odd%=mod;
		}
		else{
			evn+=min(tmp,l);l-=min(tmp,l);tmp*=2ll;
			if(evn>=mod)evn%=mod;
		}
		trn++;
	}
	//cout<<"odd= "<<odd<<"evn "<<evn<<"\n";
	ll ans1=0;
	ans1+=(odd*odd)%mod;
	ans1+=(evn*(evn+1ll))%mod;
	evn=0,odd=0;
	tmp=1ll;trn=1;
	while(r){
		if(trn%2){
			odd+=min(tmp,r);r-=min(tmp,r);tmp*=2ll;
			if(odd>=mod)odd%=mod;
		}
		else{
			evn+=min(tmp,r);r-=min(tmp,r);tmp*=2ll;
			if(evn>=mod)evn%=mod;
		}
		trn++;
	}
	//cout<<"odd= "<<odd<<"evn= "<<evn<<"\n";
	ll ans2=0;
	ans2+=(odd*odd)%mod;
	ans2+=(evn*(evn+1ll))%mod;
	ll ans=(ans2-ans1);
	if(ans>=mod)ans%=mod;
	while(ans<0)ans+=mod;
	cout<<ans<<"\n";
	return 0;

}