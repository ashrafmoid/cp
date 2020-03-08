#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	int f1[30],f2[30];
	string s,t;
	while(q--){
		cin>>s>>t;
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(int i=0;i<s.size();i++)f1[s[i]-'a']++;
		for(int i=0;i<t.size();i++)f2[t[i]-'a']++;
		int flg=0;
		for(int i=0;i<26;i++){
			if(f1[i]&&f2[i]){flg=1;break;}
		}
		if(flg)cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}