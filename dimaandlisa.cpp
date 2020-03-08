#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chck(ll n){
	if(n==0)return 1;
	if(n==1)return 0;
	int flg=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){flg=0;break;}
	}
	return flg;
}
int main(){
	ll n;cin>>n;
	if(chck(n)){cout<<"1\n"<<n;return 0;}
	//if(n==3){cout<<"1\n3\n";return 0;}
	ll a1=0;
	for(ll i=n-1;i>=2;i--){
		if(chck(i)){a1=i;break;}
	}
	n-=a1;int a2=-1,a3=-1;
	for(int i=2;i<=n;i++){
		if(chck(i) && chck(n-i)){a2=i,a3=n-i;break;}
	}
	if(a2<=0 && a3<=0){cout<<"1\n"<<a1<<"\n";}
	else if(a2<=0 ){
		cout<<"2\n"<<a1<<" "<<a3<<"\n";
	}
	else if(a3<=0){
		cout<<"2\n"<<a1<<" "<<a2<<"\n";
	}
	else{
		cout<<"3\n"<<a1<<" "<<a2<<" "<<a3<<"\n";
	}
	return 0;
}