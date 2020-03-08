#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
	int a[100001];
	for(int i=1;i<=n;i++)cin>>a[i];
	int l[100002];
	l[n+1]=0;
	map<int,int> mp;
	for(int i=n;i>0;i--){
		l[i]=l[i+1];
		if(mp.find(a[i])==mp.end())l[i]++;
		mp[a[i]]++;
	}
	for(int i=0;i<m;i++){
		int x;cin>>x;
		cout<<l[x]<<"\n";
	}
	return 0;
}