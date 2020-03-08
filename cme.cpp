#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int q;cin>>q;
	for(int i=0;i<q;i++){
		ll n;cin>>n;
		if(n==2){cout<<"2\n";}
		else if(n==3){cout<<"1\n";}
		else if((n-4)%2)cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
}