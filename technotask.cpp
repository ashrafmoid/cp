#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int tree[4*maxn];
int a[maxn];
void build(int root,int l,int r){
	if(l>r )return ;
	if(l==r){
		tree[root]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*root,l,mid);
	build(2*root+1,mid+1,r);
	int flg=0;
	if(a[mid]==1 && a[mid+1]==1)flg=1;
	tree[root]=tree[2*root]+tree[2*root+1]-flg;
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
	int flg=0;
	if(a[mid]==1 && a[mid+1]==1)flg=1;
	tree[root]=tree[2*root]+tree[2*root+1]-flg; 
	return;
}
int query(int root,int l,int r,int be,int en){
	if(en<l || be >r )return 0;
	if(be >=l && en<=r)return tree[root];
	int mid=(be+en)/2;
	int flg=0;
	if(a[mid]==1 && a[mid+1]==1 && mid>=l-1 && mid<=r)flg=1;
	int res=query(2*root,l,r,be,mid)+query(2*root+1,l,r,mid+1,en)-flg;
	return res;
}

int main(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    for(int i=0;i<q;i++){
        int opt;cin>>opt;
        if(opt==1){
            int x;cin>>x;x--;
            int val=!a[x];
            update(1,0,n-1,x,val);
        }
        else{
            int l,r;cin>>l>>r;
            l--;r--;
            cout<<query(1,l,r,0,n-1)<<"\n";
        }
    }
    return 0;
}