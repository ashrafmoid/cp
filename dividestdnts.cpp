#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		int eql=(a+b+c)/3;
		if(eql*3 !=(a+b+c))eql++;
		int minn=min(a,c);
		int maxx=max(a,c);
		int dif=eql-minn;
		if(dif<0)dif=0;
		dif=min(dif,b);
		minn+=dif;
		b-=dif;
		int tmp=maxx+b;
		int ans=max(minn,max(tmp/2,tmp-tmp/2));
		cout<<ans<<"\n";
	}
	return 0;
}