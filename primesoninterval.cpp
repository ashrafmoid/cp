#include<bits/stdc++.h>
using namespace std;
int isprime[1000001];
int vis[1000001];
int main(){
	//isprime[1]=isprime[0]=1;
	for(int i=2;i<=1000000;i++){
		if(vis[i])continue;
		vis[i]=1;
		isprime[i]=1;
		for(int j=2*i;j<1000001;j+=i)vis[j]=1;
	}
	int a,b,k;cin>>a>>b>>k;
	int ans=INT_MAX;
	int cnt=0;
	int l=a,r=a;
	while(l<=r && r<=b){
		if(cnt>=k){
			cout<<"l= "<<l<<"r= "<<r<<"\n";
			ans=min(ans,r-l);
			if(isprime[l])cnt--;l++;
		}
		else{
			if(isprime[r])cnt++;
			r++;
		}
	}
	while(cnt>=k && l<=r){
		ans=min(ans,r-l);
		if(isprime[l])cnt--;
		l++;
	}
	if(ans==INT_MAX)cout<<"-1\n";
	else 
	cout<<ans<<"\n";
	return 0;
}