#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>a;
int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++){int x;cin>>x;a.push_back(x);};
	sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());
	int ans=0;
	int len=a.size();
	for(int i=0;i<len-1;i++){
		int x=i+1;
		while(x<len){
			int tmp=a[x]/a[i];
			x=lower_bound(a.begin(),a.end(),a[i]*(tmp+1))-a.begin()-1;
			ans=max(ans,a[x]%a[i]);
			x++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}