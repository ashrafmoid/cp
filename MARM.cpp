#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10003];
int main(){
	int t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		//k--;
		for(int i=0;i<n;i++)cin>>a[i];
		if(n%2 && 2*k>n)a[n/2]=0;
		k=k%(3ll*n);
		for(int i=0;i<k;i++){
			int frst=i%n;
			int scnd=n-frst-1;
			a[frst]=a[frst]^a[scnd];
		}
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}