#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		int l=0,r=n-1;
		int cur=0;int tmp=0;
		for(int j=20;j>=0;j--){
			if(a[i]&(1<<j)){
				int x=lower_bound(a+l,a+r+1,cur+(1<<j))-a;x--;
				if(x<=r){
					r=min(x,r);tmp+=(1<<j);
				}
				else{
					cur+=(1<<j);
				}
			}
			else{
				int x=lower_bound(a+l,a+r+1,cur+(1<<j))-a;
				if(x>=l && x<n){
					l=x;tmp+=(1<<j);
				}
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}