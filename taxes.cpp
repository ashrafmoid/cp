#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chck(ll n){
	int flg=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i ==0 ){flg=1;break;}
	}
	return flg;
}
int main(){
	ll n;cin>>n;
	if(n<=3){cout<<"1\n";return 0;}
	int flg=chck(n);
	if(flg){
		if(n%2 ==0 ){cout<<"2\n";return 0;}
		int ans=1;int tmp=n-3;
		if(chck(tmp)==0)ans=2;
		else ans=3;
		if(chck(n-2)==0)ans=2;
		cout<<ans<<"\n";
		return 0;
	}
	else{cout<<"1\n";return 0;}
	return 0;
}