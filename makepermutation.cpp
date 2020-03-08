#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
//int extra[maxn];
int res[maxn];
int svd[maxn];
queue<int> q;
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		a[res[i]]++;
		//if(a[res[i]]>1)extra[res[i]]=a[res[i]];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		ans++;q.push(i);
	}
	for(int i=1;i<=n;i++){
		if(q.empty() )continue;
		else if(a[res[i]]==1 && svd[res[i]]==0){svd[res[i]]=1;a[res[i]]--;continue;}
		else if(a[res[i]]==1 && svd[res[i]]){
			a[res[i]]--;res[i]=q.front();q.pop();
		}
		else if(svd[res[i]]){
			a[res[i]]--;res[i]=q.front();q.pop();
		}
		else{
			if(res[i]<q.front()){
				a[res[i]]--;svd[res[i]]=1;
			}
			else{
				a[res[i]]--;res[i]=q.front();q.pop();
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	return 0;
}