#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int trck[100005];
int a[100005];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];trck[a[i]]=i;}
	a[0]=0;trck[a[0]]=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			ans+=1ll*(a[i]-a[i-1])*(n-a[i]+1);
		}
		else{
			ans+=1ll*(a[i])*(a[i-1]-a[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}