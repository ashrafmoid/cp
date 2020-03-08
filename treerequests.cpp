#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SYN ios_base::sync_with_stdio(false),cin.tie(NULL)
ll ans[100005];
//int lft[100005],rht[100005];
map<ll,int> lft,rht;
int main(){
	SYN;
	int n;cin>>n;
	set<int>st;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		if(i==1){st.insert(x);continue;}
		auto it=st.lower_bound(x);
		if(it!=st.end() && lft.find(*it)==lft.end()){
			ans[i]=*it;
			st.insert(x);
			lft[*it]++;
		}
		else {
			it--;
			rht[*it]++;
			ans[i]=*it;
			st.insert(x);
		}
	}
	for(int i=2;i<=n;i++)cout<<ans[i]<<" ";
		return 0;
	
}