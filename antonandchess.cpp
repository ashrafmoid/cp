#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll>P;
const int maxn=5e5+5;
vector<P> v[3];
ll x_c,y_c;
int get_val(char val){
	if(val=='B')return 0;
	if(val=='R')return 1;
	return 2;
}
int check0(int v1,int v2){
	ll theta=1e10;
	for(int j=0;j<3;j++){
		if(j==1)continue;
		for(int i=0;i<v[j].size();i++){
			if(v1<0 && v2<0 && (x_c-v[j][i].first)==(y_c-v[j][i].second)&&(y_c-v[j][i].second)>0){
				theta=min(theta,x_c-v[j][i].first);
			} 
			if(v1>0 && v2>0 && (v[j][i].first-x_c)==(v[j][i].second-y_c)&&(v[j][i].second-y_c)>0){
				theta=min(theta,v[j][i].first-x_c);
			} 
			if(v1<0 && v2>0 && (x_c-v[j][i].first)==(v[j][i].second-y_c)&&(v[j][i].second-y_c)>0){
				theta=min(theta,x_c-v[j][i].first);
			} 
			if(v1>0 && v2<0 && (v[j][i].first-x_c)==(y_c-v[j][i].second)&&(y_c-v[j][i].second)>0){
			theta=min(theta,v[j][i].first-x_c);
			} 
		}
	}
	if(theta==1e10){return -1;}
	ll theta2=1e10;
	for(int i=0;i<v[1].size();i++){
		if(v1<0 && v2<0 && (x_c-v[1][i].first)==(y_c-v[1][i].second)&& (y_c-v[1][i].second)>0){
			theta2=min(theta2,x_c-v[1][i].first);
			} 
		if(v1>0 && v2>0 && (v[1][i].first-x_c)==(v[1][i].second-y_c)&&(v[1][i].second-y_c)>0){
			theta2=min(theta2,v[1][i].first-x_c);
		} 
		if(v1<0 && v2>0 && (x_c-v[1][i].first)==(v[1][i].second-y_c) && (v[1][i].second-y_c)>0){
			theta2=min(theta2,x_c-v[1][i].first);
		} 
		if(v1>0 && v2<0 && (v[1][i].first-x_c)==(y_c-v[1][i].second) &&(y_c-v[1][i].second)>0 ){
			theta2=min(theta2,v[1][i].first-x_c);
		} 
	}
	if(theta2<theta){return -1;}
	return 1;

}
int check1(int v1){
	ll theta=1e10;
	for(int j=1;j<3;j++){
		for(int i=0;i<v[j].size();i++){
			if(v1==1 && y_c==v[j][i].second && x_c<v[j][i].first){
				theta=min(theta,v[j][i].first-x_c);
			}
			if(v1==2 && y_c==v[j][i].second && x_c>v[j][i].first){
				theta=min(theta,x_c-v[j][i].first);
			}
			if(v1==3 && x_c==v[j][i].first && y_c>v[j][i].second){
				theta=min(theta,y_c-v[j][i].second);
			}
			if(v1==4 && x_c==v[j][i].first && y_c<v[j][i].second){
				theta=min(theta,v[j][i].second-y_c);
			}
		}
	}
	if(theta==1e10)return -1;
	ll theta2=1e10;
	for(int i=0;i<v[0].size();i++){
		if(v1==1 && y_c==v[0][i].second && x_c<v[0][i].first){
				theta2=min(theta2,v[0][i].first-x_c);
			}
			if(v1==2 && y_c==v[0][i].second && x_c>v[0][i].first){
				theta2=min(theta2,x_c-v[0][i].first);
			}
			if(v1==3 && x_c==v[0][i].first && y_c>v[0][i].second){
				theta2=min(theta2,y_c-v[0][i].second);
			}
			if(v1==4 && x_c==v[0][i].first && y_c<v[0][i].second){
				theta2=min(theta2,v[0][i].second-y_c);
			}
	}
	if(theta2<theta)return -1;
	return 1;

}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	int n;cin>>n;
  	cin>>x_c>>y_c;
  	for(int i=0;i<n;i++){
  		ll x,y;char z;cin>>z>>x>>y;
  		//cout<<z<<"\n";
  		int indx=get_val(z);
  		v[indx].pb(mp(x,y));
  	}
  	int ans=-1;
  	for(int i=-1;i<=1;i++){
  		for(int j=-1;j<=1;j++){
  			if(i==0 || j==0)continue;
  			ans=max(ans,check0(i,j));
  			//ans=max(ans,check1(i,j));
  			if(ans>0){;cout<<"YES\n";return 0;}
  		}
  	}
  	for(int i=1;i<5;i++){
  		ans=max(ans,check1(i));
  		if(ans>0){cout<<"YES\n";return 0;}
  	}
  	cout<<"NO\n";
  	return 0;

  	return 0;
}