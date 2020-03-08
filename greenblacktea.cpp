#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll>P;
const int maxn=2e5+5;
//ll a[maxn];
//ll suf[maxn],pre[maxn];
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n,k,a,b;cin>>n>>k>>a>>b;
  	int maxx=max(a,b);
  	int minn=min(a,b);
  	int z=maxx/k + int(maxx%k!=0);
  	//cout<<"z="<<z<<"\n";
  	int r=maxx%k;
  	if(minn<z-1){cout<<"NO\n";return 0;}
  	if(b>a){
  		int cnt1=z-1;int cnt2=a-z+1;
  		for(int i=0;i<2*k;i++){
  			if(i%2==0 && cnt2){cout<<"G";cnt2--;}
  			if(i%2 && b){cout<<"B";b--;}
  		}
  		while(b || cnt1){
  			if(cnt1){cout<<"G";cnt1--;}
  			for(int i=0;i<2*k-2;i++){
  				if(i%2==0 && b){cout<<"B";b--;}
  				if(i%2 && cnt2){cout<<"G";cnt2--;}
  			}
  			if(b){cout<<"B";b--;}
  		}
  	}
  	else{
  		swap(a,b);
  		int cnt1=z-1;int cnt2=a-z+1;
  		for(int i=0;i<2*k;i++){
  			if(i%2==0 && cnt2){cout<<"B";cnt2--;}
  			if(i%2 && b){cout<<"G";b--;}
  		}
  		while(b || cnt1){
  			if(cnt1){cout<<"B";cnt1--;}
  			for(int i=0;i<2*k-2;i++){
  				if(i%2==0 && b){cout<<"G";b--;}
  				if(i%2 && cnt2){cout<<"B";cnt2--;}
  			}
  			if(b){cout<<"G";b--;}
  		}
  	}
  	return 0;
}