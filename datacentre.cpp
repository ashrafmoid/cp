#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int lo=sqrt(n);
	int ans=INT_MAX;
	for(int i=lo;i>=1;i--){
		if(n%i==0){ans=min(ans,2*(i+n/i));break;}
	}
	for(int i=lo;i<=n;i++){
		if(n%i==0){ans=min(ans,2*(i+n/i));break;}
	}
	cout<<ans<<"\n";
	return 0;
}