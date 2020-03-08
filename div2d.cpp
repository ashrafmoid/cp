#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef struct node{
	ll a,b;
}node;
node q[100005];
bool cmp(node x,node y){
	return ((x.a-x.b)<(y.a-y.b));
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i].a>>q[i].b;
	}
	sort(q,q+n,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*(n-i+1)*(q[i-1].a-q[i-1].b);
		ans+=n*q[i-1].b-q[i-1].a;
	}
	cout<<ans<<"\n";
	return 0;
}