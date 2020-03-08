#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[101];
int cmp(pair<int,int> p1,pair<int,int>p2){
	if(p1.first!=p2.first)return p1.first<o2.first;
	return p1.second>p2.second;
}
int main(){
	int n,r;cin>>n>>r;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		p[i]=make_pair(a,b);
	}
	sort(p,p+n,cmp);
}