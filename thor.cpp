#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
//vector<int> v[maxn];
set<int> st[maxn];
int mrk[maxn];
queue<pair<int,int> > qu;
int ans=0;
int main(){
  int cnt=1;
  int n,q;cin>>n>>q;
  for(int i=1;i<=q;i++){
    int typ,x;cin>>typ>>x;
    if(typ==1){
      //st.insert(make_pair(cnt,x));
      //e[x].push_back(cnt);
      qu.push(make_pair(cnt,x));
      st[x].insert(cnt);
      ans++;cnt++;
    }
    else if(typ==2){
      for(auto it:st[x]){
        ans--;mrk[it]=1;
      }
      st[x].clear();
      //e[x].clear();
    }
    else{
      while(!qu.empty() && qu.front().first<=x){
        pair<int,int> p=qu.front();qu.pop();
        //st.erase(st.begin)());
        if(!mrk[p.first]){
          mrk[p.first]=1;ans--;
          st[p.second].erase(p.first);
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
