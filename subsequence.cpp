#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn];
ll bit[12][maxn];
void update(int t,int x,ll val){
  for(;x<maxn;x+=x&-x)bit[t][x]+=val;
  return ;
}
ll query(int t,int x){
  ll ans=0;
  for(;x>0;x-=x&-x)ans+=bit[t][x];
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
    update(1,a[i],1);
    for(int j=2;j<=k+1;j++){
      ll tmp=query(j-1,a[i]-1);
      update(j,a[i],tmp);
    }
  }
  cout<<query(k+1,n)<<"\n";
  return 0;
}
