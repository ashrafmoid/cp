#include<bits/stdc++.h>
using namespace std;
int f[50];
int main(){
	string s;cin>>s;
	int k;cin>>k;
	for(int i=0;i<30;i++)f[i]=-1;
	for(int i=0;i<k;i++){
		char x,y;cin>>x>>y;
		f[x-'a']=y-'a';
		f[y-'a']=x-'a';
	}
	int len=s.size();
	int ans=0;
	int tmp[30];
	for(int i=0;i<len;){
		memset(tmp,0,sizeof(tmp));
		int j=i+1;
		while(j<len && (f[s[j]-'a']==(s[i]-'a') || f[s[i]-'a']==(s[j]-'a') || s[i]==s[j])){
			tmp[s[i]-'a']++;
			i++;j++;
		}
		tmp[s[i]-'a']++;
		int minn=100005;
		int flg=0;
		for(int x=0;x<26;x++)if(tmp[x]!=0){minn=min(minn,tmp[x]);flg++;}
		if(flg>1)
		ans+=minn;
		i=j;
		//cout<<"i= "<<i<<" ans= "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}