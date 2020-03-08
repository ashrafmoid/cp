#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
ll  mod=1e9+7;
const int maxn=1e5+5;
//ll a[2*maxn];
//vector<ll> pos,neg;
vector<ll> ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;cin>>q;
  for(int i=0;i<q;i++){
    ll a,b,m;cin>>a>>b>>m;
    ll lo=1-m,hi=m-1;
    //ans.pb(a);
    ll nxt=a;
    int flg=0;
    if(b-a>=1 && b-a<=m){cout<<"2 "<<a<<" "<<b<<"\n";continue;}
    else if(b-a==0){cout<<"1 "<<a<<"\n";continue;}
    else{
      for(int j=0;j<50;j++){
        if(b-a>=lo && b-a <=hi){ans.pb(b);ans.pb(a);break;}
        if(b<a){flg=1;break;}
        if(b%2==0){ans.pb(b);b/=2;}
        else if(1<=hi && (b%2)){
          ans.pb(b);b--;b/=2;
        }
        else {flg=1;break;}
      }
    }
    if(flg){cout<<"-1\n";ans.clear();continue;}
    cout<<ans.size()<<" ";
    for(int j=ans.size()-1;j>=0;j--)cout<<ans[j]<<" ";
      cout<<"\n";
    ans.clear();
  }
  return 0;
}
