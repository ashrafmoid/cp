#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int a[104];
    int t;cin>>t;
    while(t--){
    	ll n;cin>>n;
    	for(int i=0;i<n;i++)cin>>a[i];
    	sort(a,a+n);
    	int ans=1;
    	int flg=0;
    	//int cnt=0;
    	for(int i=0;i<n-1;i++){
    		if(a[i]+1==a[i+1])flg=1;
    	}
    	ans+=flg;
    	cout<<ans<<"\n";
    }
    return 0;
}