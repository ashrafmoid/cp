#include<bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  const int maxn=1e5+5;
  ll tree[maxn];
  int n;
  typedef struct node{
    ll a,b,h;
  }node;
  node q[maxn];
  vector<ll> v;
  ll a[maxn];
  int len;
  bool cmp(node x,node y){
    if(x.b!=y.b)return x.b>y.b;
    return x.a>=y.a;
  }
  void update(int x,ll val){
    x++;
    for(;x<=len;x+=x&-x){tree[x]=max(tree[x],val);}
    return ;
  }
  ll query(int x){
   x++;
    ll ans=0;
    for(;x>0;x-=x&-x)ans=max(tree[x],ans);
    return ans;
  }
  int main(){
    ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
    cin>>n;
    memset(tree,0,sizeof(tree));
    for(int i=0;i<n;i++){cin>>q[i].a>>q[i].b>>q[i].h;v.push_back(q[i].a);}
    sort(q,q+n,cmp);//int cnt=0;for(int i=0;i<n;i++)a[cnt++]=q[i].a;
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    //len=v.size();
     len=v.size();
    //cout<<"len= "<<len<<"\n";
    ll ans=0;
    for(int i=0;i<n;i++){
      int indx=lower_bound(v.begin(),v.end(),q[i].b-1ll)-v.begin();if(indx>=len ||v[indx]>=q[i].b)indx--;
      ll tmp=query(indx)+q[i].h;
      ans=max(ans,tmp);
      //cout<<"b= "<<q[i].b<<" ans= "<<ans<<"\n";
      indx=lower_bound(v.begin(),v.end(),q[i].a)-v.begin();
      update(indx,tmp);
    }
    cout<<ans<<"\n";
    return 0;
  }
