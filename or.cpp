#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll>P;
const int maxn=2e5+5;
ll a[maxn];
ll suf[maxn],pre[maxn];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n,k;ll x;cin>>n>>k>>x;
  	for(int i=0;i<n;i++){cin>>a[i];if(i)pre[i]=pre[i-1]|a[i-1];}
  	//sort(a,a+n,cmp);
  	for(int i=n-1;i>=0;i--){
  		if(i<n-1)suf[i]=suf[i+1]|a[i+1];
  	}
  	ll ans=0;
  	ll tmp=1;
  	for(int i=0;i<k;i++)tmp*=x;
  		//ans=max(ans,tmp*a[0]|suf[1])
  	for(int i=0;i<n;i++){
  		ans=max(ans,pre[i]|(tmp*a[i])|suf[i]);
  	}
  	cout<<ans<<"\n";
  return 0;

}