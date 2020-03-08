#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int k=2;
typedef long long ll;

typedef struct vertex {
	int next[k];
    bool leaf = false;
    int cnt=0;
    vertex() {
        fill(begin(next), end(next), -1);
    }
}vertex ;
int s[2][30];
vector<vertex> trie;
//int x[30],s[30];
void add_string(int* s) {
    int v = 0;
    int len=30;
    for (int i=len-1;i>=0;i--) {
        int c = s[i];
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        trie[v].cnt++;
      //  cout<<"--"<<trie[v].cnt<<"\n";
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
    trie[v].cnt++;
    return ;
}
int query(int* s,int * x){
    int v=0;int ans=0;
    int len=30;
    for(int i=len-1;i>=0;i--){
        if(v==-1)return ans;
        if(x[i]==0){
            if(trie[v].next[s[i]]==-1)return ans;
            v=trie[v].next[s[i]];
        }
        else{
            if(trie[v].next[s[i]]!=-1)ans+=trie[trie[v].next[s[i]]].cnt;
         //   else if(s[i]==0 && trie[v].next[0]!=-1)ans+=trie[trie[v].next[0]].cnt;
            if(trie[v].next[!s[i]]!=-1)v=trie[v].next[!s[i]];
            else return ans;
        }
    }
    ans+=trie[v].cnt;
    return ans;
}
ll a[100005];
vector<pair<ll,ll> > p;
ll ans[20];
void get_binary(ll val,int op){
    memset(s[op],0,sizeof(s[op]));
    int i=0;
    while(val){
        s[op][i]=val%2;
        i++;val/=2;
    }
    return ;
}
int main(){
    int t;cin>>t;
    while(t--){
        trie.resize(1);
        memset(ans,0,sizeof(ans));
        int n,q;cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>q;
        for(int i=0;i<q;i++){
            ll t1,t2;
          //  cin>>(p[i].first)>>(p[i].second);
            cin>>t1>>t2;
            t1--;
            p.pb(mp(t1,t2));
            
        }
        ll tmp=0;
        memset(s,0,sizeof(s));
        add_string(s[0]);
        for(int i=0;i<n;i++){
            tmp^=a[i];
            //cout<<"tmp= "<<tmp<<"\n";
            get_binary(tmp,0);
            for(int j=0;j<q;j++){
                get_binary(p[j].second,1);
                //cout<<"\n";
                //for(int y=0;y<30;y++)cout<<s[1][y];
                ans[j]+=query(s[0],s[1]);
               // cout<<"j= "<<j<<"ans = "<<ans[j]<<"\n";
                if(p[j].first>=0){
                get_binary(p[j].first,1);
                //cout<<"\n";
                //for(int y=0;y<30;y++)cout<<s[1][y];
                ans[j]-=query(s[0],s[1]);}
                // cout<<"j= "<<j<<"ans = "<<ans[j]<<"\n";
                //cout<<"j= "<<j<<"ans = "<<ans[j]<<"\n";
            }
            add_string(s[0]);
        }
        for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
        trie.clear();
        p.clear();
    }
    return 0;
}