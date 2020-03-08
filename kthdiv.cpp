#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k;cin>>n>>k;
	vector<ll>sml,lrg;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)sml.push_back(i);
		if(i*i==n)continue;
		if(n%i==0)lrg.push_back(n/i);
	}
	if(sml.size()+lrg.size()<k){cout<<"-1\n";return 0;}
	if(k<=sml.size()){cout<<sml[k-1]<<"\n";return 0;}
	int rem=k-sml.size();
	cout<<lrg[lrg.size()-rem]<<"\n";
	return 0;
}
