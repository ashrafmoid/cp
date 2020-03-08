#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL)
ll mod=1e9+7;
ll a[5005],b[5005];
ll ans=0;
vector<int>good;
int n,m;
int vis[100005];
ll gcd[5005];
int len;
ll chck(ll nm){
	ll sum=0;
	for(int i=0;i<m;i++){
		if(b[i]>nm)break;
		int cnt=0;
		while(nm%b[i]==0){nm/=b[i];cnt++;}
		sum+=cnt;
	}
	for(int i=0;i<len;i++){
		if(good[i]>nm)break;
		int cnt=0;
		while(nm%good[i]==0){nm/=good[i];cnt--;}
		sum+=cnt;
	}
	return sum;
}
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	fast_io;
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	gcd[0]=a[0];
	for(int i=0;i<m;i++){cin>>b[i];if(b[i]<=40000)vis[b[i]]=1;}
	for(int i=1;i<n;i++){
		gcd[i]=__gcd(a[i],gcd[i-1]);
		//cout<<" i= "<<i <<"gcd =" <<gcd[i]<<"\n";
	}
	//cout<<"yr\n";
	for(int i=2;i<=40000;i++){
		if(vis[i])continue;
		good.pb(i);
		for(int j=i;j<=40000;j+=i)vis[j]=1;
	}
	//cout<<"og\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int cnt=0;
			while(a[j]%b[i]==0){a[j]/=b[i];cnt--;}
			ans+=cnt;
		}
	}
	//cout<<"ya\n";
	len=good.size();
	for(int i=0;i<len;i++){
		for(int j=0;j<n;j++){
			int cnt=0;
			while(a[j]%good[i]==0){a[j]/=good[i];cnt++;}
			ans+=cnt;
		}
	}
	//cout<<"hm\n";
	for(int i=0;i<n;i++)if(a[i]>1)ans++;
	//cout<<ans<<"\n";
	for(int i=n-1;i>=0;i--){
		if(gcd[i]==1)continue;
		ll res=chck(gcd[i]);
		if(res>0){
			ans+=1ll*(i+1)*res;
			for(int j=0;j<=i;j++)gcd[j]/=gcd[i];
		}
	}
	cout<<ans<<"\n";
	return 0;

}