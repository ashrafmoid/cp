#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;cin>>t;
	int p[200005];
	int used[200005];
	//vector<int> v;
	int ans[200005];
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){cin>>p[i];used[i]=0;}
		//v.clear();
		//memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++){
			if(used[i])continue;
			int len=1;
			int tmp=i;
			used[i]=1;
			while(i!=p[tmp]){
				//used[tmp]=1;
				tmp=p[tmp];
				used[tmp]=1;
				len++;
			}
			ans[i]=len;
			tmp=i;
			while(i!=p[tmp]){ans[tmp]=len;tmp=p[tmp];}
			ans[tmp]=len;
			//v.push_back(len);
		}
		//int ans=1;
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		//cout<<ans<<"\n";
	}
	return 0;
}