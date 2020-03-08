#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int m;cin>>m;
	int q[m];for(int i=0;i<m;i++)cin>>q[i];
	int n;cin>>n;
	int a[n];for(int i=0;i<n;i++)cin>>a[i];
	sort(q,q+m);sort(a,a+n);
	int i=n-1;
	long long int ans=0;
	while(i>=0){
		for(int j=0;j<q[0]&&i>=0;j++){ans+=1ll*a[i];i--;}
		i-=2;
	}
	cout<<ans<<"\n";
	return 0;
}