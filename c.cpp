#include<bits/stdc++.h>
using namespace std;
//int a[10002];
typedef long long ll;
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main(){
	//set<pair<int,int> >st;
	 ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int n;cin>>n;
	ll prv=0;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		prv=gcd(x,prv);
		//cout<<prv<<"\n";
	}
	ll ans=0;
	for(ll i=1;i*i<=prv;i++){
		if(prv%i==0)ans+=2;
		if(i*i==prv)ans--;
	}
	cout<<ans<<"\n";
	return 0;
}