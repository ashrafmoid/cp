#include<bits/stdc++.h>
using namespace std;
int main(){
	const int maxn=1e5+5;
int tree[4*maxn];
void build(int root,int l,int r){
	if(l>r )return ;
	if(l==r){
		tree[root]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*root,l,mid);
	build(2*root+1,mid+1,r);
	tree[root]=tree[2*root]+tree[2*root+1];
	return ;
}
void update(int root,int l,int r,int indx,int val){
	if(indx<l || indx >r || l>r )return ;
	if(l== r){
		a[indx]=val;
		tree[root]=val;
		return ;
	}
	int mid=(l+r)/2;
	if(indx<=mid)
	update(2*root,l,mid,indx,val);
	else update(2*root+1,mid+1,r,indx,val);
	tree[root]=tree[2*root]+tree[2*root+1];
	return;
}
int query(int root,int l,int r,int be,int en){
	if(en<l || be >r )return 0;
	if(be >=l && en<=r)return tree[root];
	int mid=(be+en)/2;
	return query(2*root,l,r,be,mid)+query(2*root+1,l,r,mid+1,en);
}


}