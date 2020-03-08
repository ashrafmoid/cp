#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5; 
ll inf=-1e14-1e7;
typedef struct vertex{
	ll sum=0;
	//int s,e;
	ll suf=0,pre=0,mx=0;
}vertex;

//int tree[4*maxn];
vector<vertex> tree(4*maxn);
ll a[maxn];
void build(int root,int l,int r){
	if(l>r )return ;
	if(l==r){
		tree[root].mx=a[l];
		tree[root].suf=a[l];
		tree[root].pre=a[r];
		tree[root].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*root,l,mid);
	build(2*root+1,mid+1,r);
	if(tree[2*root].sum<0 || tree[2*root+1].sum<0)
		tree[root].sum=inf;
	else tree[root].sum=tree[2*root].sum+tree[2*root+1].sum;
	//int s1=tree[2*root].s,e1=tree[2*root].e;
	ll tmp=max(tree[2*root].mx,tree[2*root+1].mx);
	tmp=max(tmp,tree[root].sum);
	// if(tmp<tree[2*root+1].sum){
	// 	tmp=tree[2*root+1].sum;s1=tree[2*root+1].s;e1=tree[2*root+1].e;
	// }
	if(tree[2*root].suf>=0 &&tree[2*root+1].pre >=0 && tmp<=tree[2*root].suf+tree[2*root+1].pre){
		tmp=tree[2*root+1].pre+tree[2*root].suf;	
	}
	tree[root].mx=tmp;
	tree[root].suf=tree[2*root+1].suf;
	if(tree[2*root+1].sum>=0 && tree[2*root].suf >=0 &&( tree[2*root].suf + tree[2*root+1].sum >=tree[root].suf) ){
		tree[root].suf=tree[2*root].suf + tree[2*root+1].sum;
	}
	tree[root].pre=tree[2*root].pre;
	if(tree[2*root].sum>=0 && tree[2*root+1].pre>=0 && ( tree[2*root].sum + tree[2*root+1].pre >=tree[root].pre)){
		tree[root].pre=( tree[2*root].sum + tree[2*root+1].pre );
	}
	//tree[root]=tree[2*root]+tree[2*root+1];
	return ;
}
void update(int root,int l,int r,int indx,ll val){
	if(indx<l || indx >r || l>r )return ;
	if(l== r){
		a[indx]=val;
		tree[root].mx=a[l];
		tree[root].suf=a[l];
		tree[root].pre=a[r];
		tree[root].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	if(indx<=mid)
	update(2*root,l,mid,indx,val);
	else update(2*root+1,mid+1,r,indx,val);
	
	if(tree[2*root].sum<0 || tree[2*root+1].sum<0)
		tree[root].sum=inf;
	else tree[root].sum=tree[2*root].sum+tree[2*root+1].sum;
	//int s1=tree[2*root].s,e1=tree[2*root].e;
	ll tmp=max(tree[2*root].mx,tree[2*root+1].mx);
	tmp=max(tmp,tree[root].sum);
	// if(tmp<tree[2*root+1].sum){
	// 	tmp=tree[2*root+1].sum;s1=tree[2*root+1].s;e1=tree[2*root+1].e;
	// }
	if(tree[2*root].suf>=0 &&tree[2*root+1].pre >=0 && tmp<=tree[2*root].suf+tree[2*root+1].pre){
		tmp=tree[2*root+1].pre+tree[2*root].suf;	
	}
	tree[root].mx=tmp;
	tree[root].suf=tree[2*root+1].suf;
	if(tree[2*root+1].sum>=0 && tree[2*root].suf >=0 &&( tree[2*root].suf + tree[2*root+1].sum >=tree[root].suf) ){
		tree[root].suf=tree[2*root].suf + tree[2*root+1].sum;
	}
	tree[root].pre=tree[2*root].pre;
	if(tree[2*root].sum>=0 && tree[2*root+1].pre>=0 && ( tree[2*root].sum + tree[2*root+1].pre >=tree[root].pre)){
		tree[root].pre=( tree[2*root].sum + tree[2*root+1].pre );
	}
	
	return;
}
/*ll query(int root,int l,int r,int be,int en){
	if(en<l || be >r )return 0;
	if(be >=l && en<=r)return tree[root];
	int mid=(be+en)/2;
	return query(2*root,l,r,be,mid)+query(2*root+1,l,r,mid+1,en);
}*/


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
		build(1,0,n-1);
	for(int i=0;i<n;i++){
		int x;cin>>x;x--;
		update(1,0,n-1,x,inf);
		//cout<<"update no :"<<i<<"\n";
		if(tree[1].mx>=0)
		cout<<(tree[1].mx)<<"\n";
		else cout<<"0\n";
	}
	return 0;
}