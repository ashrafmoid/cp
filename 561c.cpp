#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
ll  mod=1e9+7;
const int maxn=1e5+5;
ll a[2*maxn];
vector<ll> pos,neg;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  for(int i=0;i<n;i++){
    ll x;cin>>x;if(x>=0)pos.pb(x);else neg.pb(x);
  }
  ll ans=0;
  sort(pos.begin(),pos.end());
  sort(neg.begin(),neg.end());
  for(int i=0;i<pos.size();i++){
    ll tmp=pos[i];
    int val1= lower_bound(pos.begin(),pos.end(),tmp)-pos.begin();
    if(val1==i)val1++;
    int val2= upper_bound(pos.begin(),pos.end(),2*tmp)-pos.begin()-1;
    ans+=val2-val1+1;
    //cout<<"x= "<<tmp<<"ans= "<<ans<<"\n";
    val1= lower_bound(neg.begin(),neg.end(),-2*tmp)-neg.begin();
    val2= upper_bound(neg.begin(),neg.end(),-tmp)-neg.begin()-1;
    //if(val2<0)val2++;
    ans+=val2-val1+1;
   // cout<<"x= "<<tmp<<"ans= "<<ans<<"\n";
  }
  for(int i=0;i<neg.size();i++){
    ll tmp=neg[i];
    int val1= lower_bound(pos.begin(),pos.end(),-tmp+1)-pos.begin();
    int val2= upper_bound(pos.begin(),pos.end(),-2*tmp)-pos.begin()-1;
    ans+=val2-val1+1;
    //cout<<"x= "<<tmp<<"ans= "<<ans<<"\n";
    val1= lower_bound(neg.begin(),neg.end(),2*tmp)-neg.begin();
    val2= upper_bound(neg.begin(),neg.end(),tmp)-neg.begin()-1;
    if(val2==i)val2--;
    //if(val2<0)val2++;
    ans+=val2-val1+1;
    //cout<<"x= "<<tmp<<"ans= "<<ans<<"\n";
  }
  cout<<ans<<"\n";
  return 0;
}
