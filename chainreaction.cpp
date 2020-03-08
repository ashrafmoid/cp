#include<bits/stdc++.h>
using namespace std;
vector<int>pos;
pair<int,int> a[100004];
int dp[100001];
int cmp(pair<int,int> p1,pair<int,int> p2){
	return p1.first<p2.first;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i].first>>a[i].second;pos.push_back(a[i].first);}
	sort(a+1,a+n+1,cmp);
	sort(pos.begin(),pos.end());

	int ans=INT_MAX;
	if(n==1)ans=0;
	for(int i=2;i<=n;i++){
		int indx=lower_bound(pos.begin(),pos.end(),a[i].first-a[i].second)-pos.begin();
		//cout<<"indx= "<<indx;
		dp[i]=(i-indx-1) + dp[indx];
		//cout<<"dp= "<<dp[i];
		ans=min(ans,dp[i]+n-i);
		//cout<<"i= "<<i<<"ans= "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;

}