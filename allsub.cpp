#include<bits/stdc++.h>
using namespace std;
int fs[30],fr[30];
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int t;cin>>t;
	string s,r;
	while(t--){
		memset(fs,0,sizeof(fs));
		memset(fr,0,sizeof(fr));
		cin>>s>>r;
		for(int i=0;i<s.size();i++)fs[s[i]-'a']++;
		for(int i=0;i<r.size();i++)fr[r[i]-'a']++;
		string res="";
		int flg=0;
		for(int i=0;i<26;i++){
			if(fs[i]>fr[i]){flg=1;break;}
			fr[i]=fr[i]-fs[i];
		}
		if(flg){cout<<"Impossible\n";continue;}
		//string tmp="";
		for(int i=0;i<26;i++){
			if(fr[i]==0)continue;
			if(i<(s[0]-'a')){
				while(fr[i]){res+=char(i+97);fr[i]--;}
			}
		}
		int tmp=s[0]-'a'; 
		for(int j=0;j<s.size();j++){
			if(s[j]>s[0])break;
			else if(s[j]<s[0]){
				res+=s;
				s.clear();
				break;
			}
		}
		while(fr[tmp]){res+=char(97+tmp);fr[tmp]--;}
		res+=s;
		for(int i=0;i<26;i++){
			while(fr[i]){
				res+=char(97+i);fr[i]--;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}