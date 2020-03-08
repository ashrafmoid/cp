#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>op;
//vector<ll>t;
vector<pair<ll,int> > p;
//int esy[200005];
int main(){
	int m;cin>>m;
	while(m--){
		ll n,t,a,b;cin>>n>>t>>a>>b;
		op.clear();
		p.clear();
		ll tot=0;
		for(int i=0;i<n;i++){
			int x;cin>>x;op.push_back(x);
			//esy[i]=0;
			if(x==0)tot++;
		}
		//esy[n]=0;
		for(int i=0;i<n;i++){
			ll tm;cin>>tm;
			p.push_back(make_pair(tm,op[i]));
		}
		ll esy=0;
		p.push_back(make_pair(t+1,0));
		sort(p.begin(),p.end());
		int ans=0;
		ll cnt=0;
		for(int i=0;i<=n;i++){
			cnt=a*esy+b*(i-esy);
			if(cnt<p[i].first){ans=max(ans,i);
			//if(p[i].second==0)esy++;
			ll dif=p[i].first-cnt-1;
			int tmp1=min(tot-esy,dif/a);
			ans=max(ans,i+tmp1);
			dif-=a*tmp1;
			int hrd=i-esy;
			int tmp=min(n-tot-hrd,dif/b);
			ans=max(ans,i+tmp1+tmp);
			}
			if(p[i].second==0)esy++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}