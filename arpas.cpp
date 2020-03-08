#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//int a[100001];
//int f[100001];
int main(){
		int n,x;cin>>n>>x;
		map<ll,ll> f;
		ll ans=0;
		for(int i=0;i<n;i++){int a;cin>>a;
			//if(a^x<=100000)
			ans+=f[a^x];
			f[a]++;
		}
		cout<<ans<<"\n";
		return 0;

}