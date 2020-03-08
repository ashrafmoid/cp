#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
typedef struct node{
  ll B,I,R;
}node;
node  v[maxn];
bool cmp(node x,node y){
  return x.B<y.B;
}
vector<int> t;
ll tree[4*maxn];
void update(int root,int indx,int be,int en,ll val){
  if(be>en || indx >en || indx<be)return;
  if(be==en){if(be==indx)tree[root]=max(val,tree[root]);return;}
  int mid=(be+en)/2;
  if(indx<=mid)
  update(2*root,indx,be,mid,val);
  else update(2*root+1,indx,mid+1,en,val);
  tree[root]=max(tree[2*root],tree[2*root+1]);
  return;
}
ll query(int root,int l,int r,int be,int en){
  if(be>en || be>r || en <l)return 0;
  if(be>=l && en<=r){
    return tree[root];
  }
  int  mid=(be+en)/2;
  return max(query(2*root,l,r,be ,mid),query(2*root+1,l,r,mid+1,en));
}
int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n;cin>>n;
  for(int i=0;i<n;i++){cin>>v[i].B;}
  for(int i=0;i<n;i++){cin>>v[i].I;t.push_back(v[i].I);}
  for(int i=0;i<n;i++){cin>>v[i].R;}
  sort(v,v+n,cmp);
  sort(t.begin(),t.end());
  t.erase(unique(t.begin(),t.end()),t.end());
  int ans=0;
  for(int i=n-1;i>=0;){
    int j=i;
    for(;j>=0 && v[j].B==v[i].B;j--){
      int indx=upper_bound(t.begin(),t.end(),v[j].I)-t.begin();
      ll res=query(1,indx,n-1,0,n-1);
      if(res>v[j].R)ans++;
    }
    j=i;
    for(;j>=0 && v[j].B==v[i].B;j--){
      int indx=upper_bound(t.begin(),t.end(),v[j].I)-t.begin();
      indx--;
      update(1,indx,0,n-1,v[j].R);
    }
    i=j;
  }
  cout<<ans<<"\n";
  return 0;
}
