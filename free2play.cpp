#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200002];
int main(){
	int q;cin>>q;
	while(q--){
		ll h,n;cin>>h>>n;
		for(int i=n;i>0;i--)cin>>p[i];
		int ans=0;
		for(int i=n;i>0;){
			int res=p[i]-p[i-1];
			if(res>1)p[i]=p[i-1]+1;
			else{
				p[i]-=2;
				if(p[i]<=0)break;
				if(i-2>=0 && p[i]==p[i-2])i-=2;
				else {
					ans++;i--;p[i]--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}	