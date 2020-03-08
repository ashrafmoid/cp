#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int last_oc[maxn];
int frq[maxn];
int d[maxn];
int a[maxn];
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	set<pair<int,int> > st;
  	int n,m;cin>>n>>m;
  	for(int i=1;i<=n;i++)cin>>d[i];
  	for(int i=1;i<=m;i++)cin>>a[i];
  	int lo=1,hi=n;int ans=0;
  	while(lo<=hi){
  		st.clear();
  		int mid=(lo+hi)/2;
  		for(int i=1;i<=m;i++){frq[i]=a[i];last_oc[i]=n+1;}
  		for(int i=1;i<=mid;i++){
  			if(d[i]==0)continue;
  			if(st.find(make_pair(last_oc[d[i]],d[i]))!=st.end()){st.erase(make_pair(last_oc[d[i]],d[i]));}
  			last_oc[d[i]]=i;st.insert(make_pair(i,d[i]));
  		}
  		if(st.size()<m){lo=mid+1;continue;}
  		int flg=0;int rem=0;
  		for(int i=1;i<=mid;i++){
  			if(st.empty()){flg=1;break;}
  			pair<int,int> p= *st.begin();
  			if(frq[p.second]>0){
  				int tmp=min(rem,frq[p.second]);
  				rem-=tmp;frq[p.second]-=tmp;
  			}
  			if(d[i]==0){
  				//pair<int,int> p= *st.begin();
  				if(frq[p.second]){frq[p.second]--;}
  				else rem++;
  			}
  			else if(d[i]==p.second){
  				if(frq[d[i]]==0){st.erase(p);}
  				else frq[d[i]]--;
  			}
  			else {
  				if(frq[p.second]>0)frq[p.second]--;
  				else {rem++;}
  			}
  			//if(frq[p.second]==0)st.erase(p);

  		}
  		// while(rem && !st.empty()){
  		// 	pair<int,int> p= *st.begin();
  		// 	if(frq[p.second]>0){
  		// 		int tmp=min(rem,frq[p.second]);
  		// 		rem-=tmp;frq[p.second]-=tmp;
  		// 	}
  		// 	if(frq[p.second]==0)st.erase(p);
  		// }
  		if(st.empty()){ans=mid;hi=mid-1;}
  		else lo=mid+1;
  	}
  	if(ans==0){cout<<"-1\n";}
  	else cout<<ans<<"\n";
  	return 0;
}