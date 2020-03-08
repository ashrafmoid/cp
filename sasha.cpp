#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300005];
int main(){
	int n;cin>>n;
	int tmp=0;
	map<int,ll> odd;
	map<int,ll> even;
	even[0]=1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp^=a[i];
		if(i%2){ans+=odd[tmp];}
		else ans+=even[tmp];
		if(i%2)odd[tmp]++;
		else even[tmp]++;
	}
	cout<<ans<<"\n";
	return 0;

}
