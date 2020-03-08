#include<bits/stdc++.h>
using namespace std;
int a[150001];
int main(){
	ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
	int prv=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]-1>0&&a[i]-1>prv){ans++;prv=a[i]-1;}
		else if(a[i]>prv){ans++;prv=a[i];}
		else if(a[i]+1>prv) {ans++;prv=a[i]+1;}
	}
	cout<<ans<<"\n";
	return 0;
}