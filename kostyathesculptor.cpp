#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[3];
map<P,P> mp;
int ans[3];
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n;cin>>n;
  	int res=0;
  	for(int i=1;i<=n;i++){
  		for(int j=0;j<3;j++)cin>>a[j];
  		sort(a,a+3);
  		if(a[0]>=res){
  			res=a[0];
  			ans[0]=1;ans[1]=i;
  		}
  		if(!mp.count(P(a[1],a[2]))){
  			mp[P(a[1],a[2])]=P(a[0],i);
  			continue;
  		}
  		P tmp=mp[P(a[1],a[2])];
  		if(res<min(a[1],tmp.first+a[0])){
  			res=min(a[1],tmp.first+a[0]);
  			ans[0]=2;ans[1]=tmp.second;ans[2]=i;
  		}
  		if(tmp.first<a[0]){mp[P(a[1],a[2])]=P(a[0],i);}
  	}
  	cout<<ans[0]<<"\n";
  	for(int i=0;i<ans[0];i++){
  		cout<<ans[i+1]<<" ";
  	}
  	return 0;
}