#include<bits/stdc++.h>
using namespace std;
int nxt[200005][26];
int main(){
	int tst;cin>>tst;
	string s,t;
	int INF=300005;
	while(tst--){
		cin>>s>>t;
		int res=1,pos=0;
		for(int i=0;i<s.size()+5;i++)for(int j=0;j<26;j++)nxt[i][j]=INF;
		for(int i=s.size()-1;i>=0;i--){
			for(int j=0;j<26;j++)nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'a']=i;
		}
		for(int i=0;i<t.size();i++){
			if(pos==s.size()){
				pos=0;++res;
			}
			if(nxt[pos][t[i]-'a']==INF){
				pos=0;++res;
			}
			if(nxt[pos][t[i]-'a']==INF && pos==0){
				res=INF;break;
			}
			pos=nxt[pos][t[i]-'a']+1;
		}
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}