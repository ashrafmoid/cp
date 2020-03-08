#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;cin>>n;
	ll a[100005];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int res=0;ll tmp=0;
	for(int i=0;i<n;i++){
		if(tmp>a[i]){res++;continue;}
		tmp+=a[i];
	}
	cout<<(n-res)<<"\n";
	return 0;
}