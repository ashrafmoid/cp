#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
const int maxn=5e5+5;
ll n,k;
ll a[maxn];
vector<ll>v;
int l[maxn],r[maxn];
int bit[maxn];
vector<pair<int,int> > g[maxn];
void update(int x,int val){
    for(;x<=n+1;x+=x&-x)bit[x]+=val;
    return ;
}
int query(int x){
    int ans=0;
    for(;x>0;x-=x&-x)ans+=1ll*bit[x];
    return ans;
}
int main(){
    cin>>n>>k;
    //l[1]=0;
    for(int  i=1;i<=n;i++){cin>>a[i];v.pb(a[i]);}
    sort( v.begin(), v.end() );
    v.erase( unique( v.begin(), v.end() ), v.end() );
    //cout<<"YES\n";
    for(int i=1;i<=n;i++){
        l[i]=i;int j=i-1;
       // if(i==1)continue;
        while(j>=1 &&a[i]<=a[j] )j=l[j];
        l[i]=j;
    }
    //cout<<"YES\n";
     for(int i=n;i>=1;i--){
        r[i]=i;int j=i+1;
       // if(i==1)continue;
        while(j<=n && a[i] <=a[j] )j=r[j];
        r[i]=j;
    }
    //cout<<"oh"<<"\n";
    for(int i=1;i<=n;i++){
        if(i-l[i]<=r[i]-i){
            for(int j=l[i]+1;j<=i;j++){
                ll res=k-a[i]-a[j];
                int indx=upper_bound(v.begin(),v.end(),res)-v.begin()-1;
                g[r[i]-1].pb(mp(indx+1,1));
                g[i-1].pb(mp(indx+1,-1));
            }
        }
        else{
            for(int j=r[i]-1;j>=i;j--){
                ll res=k-a[i]-a[j];
                int indx=upper_bound(v.begin(),v.end(),res)-v.begin()-1;
                g[i].pb(mp(indx+1,1));
                g[l[i]].pb(mp(indx+1,-1));
            }
        }
    }
    //cout<<"hm\n";
    ll ans=0;
    for(int i=1;i<=n;i++){
        int indx=upper_bound(v.begin(),v.end(),a[i])-v.begin()-1;
        indx++;
       // cout<<"i= "<<i<<"indx= "<<indx<<"\n";
        update(indx,1);
        for(auto p:g[i]){
            ans+=1ll*query(p.first)*1ll*p.second;
        }
    }
   // cout<<"oh\n";
    cout<<ans<<"\n";
    return 0;
    
}