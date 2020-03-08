#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int row[100001],col[100001];
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,q;cin>>n>>m>>q;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		for(int i=0;i<q;i++){
			int x,y;cin>>x>>y;
			row[x]++;col[y]++;
			row[x]%=2;col[y]%=2;
		}
		int odd_r=0,odd_col=0;
		for(int i=1;i<=n;i++)if(row[i]%2)odd_r++;
		for(int i=1;i<=m;i++)if(col[i]%2)odd_col++;
		ll ans=0;
		ans+=odd_col*(1ll*n-odd_r);
		ans+=odd_r*(1ll*m-odd_col);
		cout<<ans<<"\n";
	}
	return 0;
}