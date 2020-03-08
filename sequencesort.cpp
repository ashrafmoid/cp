#include<bits/stdc++.h>
using namespace std;
int a[300005];
int bit[300005];
int lstoc[300005];
int inv[300005];
int inv2[300005];
int bit2[300005];
int lstoc2[300005];
int query(int x){
	int res=0;
	for(;x>0;x-=x&-x)res+=bit[x];
		return res;
}
void update(int x,int val,int lmt){
	for(;x<=lmt;x+=x&-x)bit[x]+=val;
	return ;
}
int query2(int x){
	int res=0;
	for(;x>0;x-=x&-x)res+=bit2[x];
		return res;
}
void update2(int x,int val,int lmt){
	for(;x<=lmt;x+=x&-x)bit2[x]+=val;
	return ;
}
int main(){
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		//bit[n]=0;
		for(int i=1;i<=n;i++){cin>>a[i];bit[i]=0;lstoc[a[i]]=i;inv[i]=0;
			update2(a[i],1,n);
			inv2[i]=i-query2(a[i]);
			//update2(a[i],1,n);
		}
		for(int i=n;i>0;i--){
			lstoc2[a[i]]=i;
			inv[i]=query(a[i]-1);
			update(a[i],1,n);
		}
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;){
			int j=i+1;
			while(j<=n&&a[j]==a[i])j++;
			if(j!=lstoc[a[i]]+inv[lstoc[a[i]]]+1)ans++;
			i=j;
		}
		int tmp=0;
		for(int i=n;i>0;){
			int j=i-1;
			while(j>0 && a[j]==a[i])j--;
			if(j!=lstoc2[a[i]]-inv2[lstoc2[a[i]]]-1)tmp++;
			i=j;
		}
		ans=min(ans,tmp);
		cout<<ans<<"\n";
	}
	return 0;
}