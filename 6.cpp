#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200003];
int main(){
	 int n,m;cin>>n>>m;
	 ll a[200001];
	 for(int i=0;i<m;i++){
	 	cin>>a[i];
	 }
	 for(int i=0;i<m-1;i++){
	 	if(a[i]==a[i+1])continue;
	 	ll minn=min(a[i],a[i+1]);
	 	ll maxx=max(a[i+1],a[i]);
	 	if(minn>1ll){
	 		p[0]+=max(a[i+1],a[i])-minn;
	 		p[minn]-=max(a[i+1],a[i])-minn;
	 	}
	 	p[minn]+=max(a[i+1],a[i])-1ll;
	 	p[minn+1]-=max(a[i+1],a[i])-1ll;;
	 	if(minn+1ll<=maxx-1ll){
	 		p[minn+1]+=abs(max(a[i+1],a[i])-minn-1ll);
	 		p[maxx]-=abs(minn+1ll-max(a[i+1],a[i]));
	 	}
	 	p[max(a[i+1],a[i])]+=minn;
	 	p[max(a[i+1],a[i])+1ll]-=minn;
	 	p[max(a[i+1],a[i])+1ll]+=max(a[i+1],a[i])-minn;
	 	p[n+1]-=max(a[i+1],a[i])-minn;
	 }
	 for(int i=1;i<=n;i++)p[i]+=p[i-1];
	 for(int i=1;i<=n;i++)cout<<p[i]<<" ";
	 return 0;

}