#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100];
int main(){
	ll n;cin>>n;
	int len=0;
	while(n){
		a[len++]=n%10;
		n/=10;
	}
	ll ans=pow(2,len)-2;
	int i=len-1;
	while(i>=0){
		if(a[i]==7){
			ans+=pow(2,i);
		}
		i--;
	}
	ans++;
	cout<<ans<<"\n";
	return 0;

}