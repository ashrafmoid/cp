#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[1048581];
ll F[1048581];

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;int maxx=0;
		memset(A,0,sizeof(A));
		memset(F,0,sizeof(F));
		for(int i=0;i<n;i++){
			int x;cin>>x;A[x]++;maxx=max(x,maxx);
		}
		int maxx_bits=0;
		int tmp2=maxx;
		while(tmp2){maxx_bits++;tmp2/=2;}
		for(int i=0;i<=maxx;i++)F[i]=A[i];
		ll ans=0;
		for(int i=0;i<21;i++){
			//if((1<<i)>maxx)break;
			for(int mask=0;mask<(1<<20);mask++){
				if((1<<i)&mask)
				F[mask]+=F[mask^(1<<i)];
			}
		}
		for(int mask=0;mask<=maxx;mask++){
			if(A[mask]==0)continue;
			//int numbits=0;
		//	int tmp=mask;while(tmp){numbits++;tmp/=2;}
			int cmplmnt=((1<<maxx_bits)-1)^mask;
			//if(cmplmnt>maxx)continue;
			//cout<<"cmplmnt= "<<cmplmnt<<" cmplmnt = "<<F[cmplmnt]<<"\n";
			ans+=1ll*A[mask]*F[cmplmnt];
		}
		cout<<ans<<"\n";
	}
	return 0;
}