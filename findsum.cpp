#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[100001];
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int t;cin>>t;
	//ll odd[100001],evn[100001];
	ll sm[100001];
	while(t--){
		int n,q;cin>>n>>q;
		//odd[0]=0;evn[0]=0;
		sm[0]=0;
		for(int i=1;i<n;i++){cin>>b[i];
			if(i%2)sm[i]=b[i]+sm[i-1];
			else sm[i]=-1ll*b[i]+sm[i-1];
		}
		while(q--){
			int p,q;cin>>p>>q;
			if(p>q)swap(p,q);
			if(abs(p-q)%2==0){cout<<"UNKNOWN\n";continue;}
			if(min(p,q)%2)cout<<(sm[q-1]-sm[p-1])<<"\n";
			else cout<<(-1*sm[q-1]+sm[p-1])<<"\n";
		}	
	}
	return 0;
}