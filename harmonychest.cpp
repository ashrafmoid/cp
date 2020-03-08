#include<bits/stdc++.h>
using namespace std;
int a[105];
vector<int> prms;
int vis[60];
int b[108];
int n;
const int lmt=(1<<17);
int dp[105][lmt];
int fct[70];
int get_fct(int num){
	return fct[num];
}
int get_ans(int indx,int bt){
	if(indx==n)return 0;
	if(dp[indx][bt]!=-1)return dp[indx][bt];
	int res=99999;int tmp=99999;
	for(int i=1;i<60;i++){
		int k2= get_fct(i);
		if(bt & k2)continue;
		tmp=abs(a[indx]-i)+get_ans(indx+1,bt|k2);
		if(res>tmp){
			res=tmp;
			b[indx]=i;
		}
	}
	dp[indx][bt]=res;
	//cout<<"indx= "<<indx<<" bit= "<< bt <<" b[indx]= "<<b[indx]<<"\n";
	return res;
}
int main(){
	for(int i=2;i<60;i++){
		if(vis[i])continue;
		prms.push_back(i);
		for(int j=i;j<60;j+=i){
			vis[j]=1;
		}
	}
	//cout<<"size of prms= "<<prms.size()<<"\n";
	for(int i=2;i<60;i++){
		int tmp=0;
		int nm=i;
		for(int j=0;j<prms.size();j++){
			if(nm<prms[j])break;
			if(nm%prms[j]!=0)continue;
			tmp|=(1<<j);
			while(nm%prms[j]==0){nm/=prms[j];}
		}
		fct[i]=tmp;
	}
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	get_ans(0,0);
	int minn=99999,min_indx=0;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<60;j++){
			if(min_indx&fct[j])continue;
			if(dp[i][min_indx]-dp[i+1][min_indx|fct[j]]==abs(a[i]-j)){b[i]=j;min_indx|=fct[j];break;}
		}
	}
	//int minn=9999;
	for(int i=1;i<60;i++){
		if(fct[i]&min_indx)continue;
		if(minn>abs(a[n-1]-i)){minn=abs(a[n-1]-i);b[n-1]=i;}
	}
	for(int i=0;i<n;i++)cout<<b[i]<<" ";
	return 0;
}