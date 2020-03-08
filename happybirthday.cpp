#include<bits/stdc++.h>
using namespace std;
int c[19];
int main(){
	int t;cin>>t;
	while(t--){
		memset(c,0,sizeof(c));
		int minn=INT_MAX;
		for(int i=0;i<10;i++){cin>>c[i];minn=min(minn,c[i]);}
		int ans=-1,num=-1;
		for(int i=1;i<=minn+1;i++){
			for(int j=1;j<10;j++){
				if(c[j]<i){num=j;ans=i;break;}
			}
			if(ans!=-1)break;
			if(c[0]<i){ans=i;num=0;break;}
		}
		string res="";
		if(num==0)res+='1';
		for(int i=0;i<ans;i++)res+=char(48+num);
		cout<<res<<"\n";
	}
	return 0;
}