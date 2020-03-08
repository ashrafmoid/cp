#include<bits/stdc++.h>
using namespace std;
//int a[100003];
//int f[100003];
//vector<pair<int,int> > v[100001];
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// for(int i=1;i<=100000;i++){
	// 	int x=i;
	// 	v[i].clear();
	// 	for(int j=2;j*j<=i && x>1;j++){
	// 		if(x%j)continue;
	// 		int cnt=0;
	// 		while(x%j==0){cnt++;x/=j;}
	// 		if(cnt==0)continue;
	// 		v[i].push_back(make_pair(j,cnt));
	// 	}
	// 	if(x>1)v[i].push_back(make_pair(x,1));
	// }
	int n,k;cin>>n>>k;
	map<vector<pair<int,int> >,int>mp;
	ll ans=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		vector<pair<int,int> >v,u;
		for(int j=2;j*j<=x;j++){
			if(x%j)continue;
			int cnt=0;
			while(x%j==0){cnt++;x/=j;}
			cnt%=k;
			if(cnt==0)continue;
			v.push_back(make_pair(j,cnt));
			u.push_back(make_pair(j,k-cnt));
		}
		if(x!=1){
			v.push_back(make_pair(x,1));
			u.push_back(make_pair(x,k-1));
		}
		ans+=mp[u];
		//cout<<"i= "<<x<<" ans= "<<ans<<"\n";
		//cout<<"res= "<<res<<" req= "<<req<<"\n";
		mp[v]++;
	}
	cout<<ans<<"\n";
	return 0;

}