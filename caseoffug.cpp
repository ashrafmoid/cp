#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<pair<ll,ll>,int > > islnd;
int cmp(pair<pair<ll,ll>,int > p1,pair<pair<ll,ll>,int > p2){
	ll d1=p1.first.second-p1.first.first;
	ll d2=p2.first.second-p2.first.first;
	return d1<=d2;
}
int main(){
	int n,m;cin>>n>>m;
	ll l,r;
	ll prvl,prvr;
	set<pair<ll,ll> >st;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(i!=0){
			pair<ll,ll> p=make_pair(l-prvr,r-prvl);
			//st.insert(p);
			islnd.push_back(make_pair(p,i-1));
		}
		prvr=r;prvl=l;
	}
	sort(islnd.begin(),islnd.end(),cmp);
	int len=n-1;
	vector<pair<ll,int> > brdg;
	for(int i=0;i<m;i++){
		ll x;cin>>x;brdg.push_back(make_pair(x,i+1));
	}
	sort(brdg.begin(),brdg.end());
	int j=0;
	int ans[n];
	for(int i=0;i<m&&len;i++){
		//cout<<"brdg="<<brdg[i].first<<"\n";
		if(brdg[i].first>=islnd[j].first.first&&brdg[i].first<=islnd[j].first.second){len--;ans[islnd[j].second]=brdg[i].second;j++;}
	}
	if(len){cout<<"No\n";return 0;}
	cout<<"Yes\n";
	for(int i=0;i<n-1;i++)cout<<ans[i]<<" ";
		return 0;

}