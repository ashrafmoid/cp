#include<bits/stdc++.h>
using namespace std;
int p[102];
int dp[102][102][102][3];
int f(int indx,int lmt,int odd,int evn,int prv){
	//cout<<"indx= "<<indx<<"\n";
	if(indx==lmt)return 0;
	int res=INT_MAX;
	if(prv!=2 && dp[indx][odd][evn][prv]!=-1)return dp[indx][odd][evn][prv];
	if(p[indx]!=0){
		int tmp=0;
		if(p[indx]%2 != prv && prv!=2)tmp++;
		res=min(tmp+f(indx+1,lmt,odd,evn,p[indx]%2),res);
	}
	else {
		if(odd>0){
			int tmp=0;
			if(1 != prv && prv!=2)tmp++;
			res=min(tmp+f(indx+1,lmt,odd-1,evn,1),res);
			//dp[indx][odd][evn][1]=res;
		}
		if(evn>0){
			int tmp=0;
			if(0 != prv && prv!=2)tmp++;
			res=min(tmp+f(indx+1,lmt,odd,evn-1,0),res);	
		}
	}
	dp[indx][odd][evn][prv]=res;
	//cout<<"indx= "<<indx<<"\n";
	return res;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	//cout<<"yo\n";
	int odd=0,evn=0;
	for(int i=0;i<n;i++){
		if(p[i]==0)continue;
		if(p[i]%2)odd++;
		else evn++;
	}
	for(int i=0;i<102;i++)for(int j=0;j<102;j++)for(int k=0;k<102;k++)for(int x=0;x<3;x++)dp[i][j][k][x]=-1;
	odd=(n+1)/2-odd;
	evn=n/2-evn;
	//cout<<"odd= "<<odd<<"evn= "<<evn<<"\n";
	cout<<f(0,n,odd,evn,2)<<"\n";
	return 0;
}