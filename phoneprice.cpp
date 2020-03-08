#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	int p[1001];
	for(int i=0;i<5;i++)p[i]=INT_MAX;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++)cin>>p[i+5];
		int ans=0;
		for(int i=5;i<n+5;i++){
			int cnt=0;
			for(int j=1;j<6;j++){
				if(p[i]<p[i-j])cnt++;
			}
			if(cnt==5)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}