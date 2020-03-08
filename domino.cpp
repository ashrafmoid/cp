#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300006];
int main(){
	int n;cin>>n;
	ll blck=0,wht=0;
	for(int i=0;i<n;i++){cin>>a[i];
		blck+=a[i]/2;
		wht+=a[i]/2;
	}
	for(int i=0;i<n;i+=2){
		blck+=a[i]%2;
	}
	for(int i=1;i<n;i+=2)wht+=a[i]%2;
	cout<<min(blck,wht)<<"\n";
	return 0;
}