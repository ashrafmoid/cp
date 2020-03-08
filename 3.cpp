#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
int main(){
	int t;cin>>t;
	ll n;
	vector<ll>v;
	int lmt=0;
	ll tmp=1e18;while(tmp){lmt++;tmp/=3;}
	ll pwr=1ll;
	for(int i=0;i<=lmt;i++){
		v.push_back(pwr);pwr*=3ll;
	}
	while(t--){
		cin>>n;
		ll ans=n;
		//cout<<"ans= "<<ans<<"\n";
		int flg=1;
		int cnt=0;
		while(flg && cnt<40){
			tmp=ans;
			for(int i=v.size()-1;i>=0;i--){
				//cout<<"tmp= "<<tmp<<"\n";
				if(tmp==0)break;
				if(v[i]>tmp)continue;
				else if(tmp/v[i]>1){ans+=v[i];flg=0;break;}
				else tmp-=v[i];
				//cout<<"tmp= "<<tmp<<"\n";
			}
			if(!flg){flg=1;}
			else break;
			cnt++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}