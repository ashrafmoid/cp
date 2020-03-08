#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;cin>>n;
	char s[300005];
	cin>>(s+1);
	ll ans=0;
	ll cont=0;
	for(int i=1;i<=n;i++){
		if(i==1 || s[i]==s[i-1]){cont++;ans+=1ll*i-1ll-(cont<i);}
		else{
			ans+=i-1-cont;cont=1ll;
		}
	}
	cout<<ans<<"\n";
	return 0;
}