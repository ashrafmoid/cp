#include<bits/stdc++.h>
using namespace std;
string s ,t;
int chck(string t1,string t2){
	int len=t1.size();
	int flg=1;
	for(int i=0;i<len;i++){
		if(t1[i]!=t2[i]){flg=0;break;}
	}
	return flg;
}
int main(){
	int n;cin>>n;
	cin>>s>>t;
	int sfx=-1;
	int i=n-1;
	while(i>=0 && s[i]==t[i]){i--;}
	//if(i<0){cout<<"26\n";return 0;}
	sfx=i;
	int prfx=n;
	i=0;
	while(i<n && s[i]==t[i])i++;
	prfx=i;
	if(prfx==sfx){cout<<"2\n";return 0;}
	string tmp1="";
	string tmp2="";
	string tmp3="";
	string tmp4="";
	for(int i=prfx;i<=sfx;i++){
		if(i==prfx){tmp2+=t[i];tmp3+=s[i];}
		else if(i==sfx){tmp1+=s[i];tmp4+=t[i];}
		else{
			tmp1+=s[i];
			tmp2+=t[i];
			tmp3+=s[i];
			tmp4+=t[i];
		}
	}
	int l1=chck(tmp1,tmp2);
	int l2=chck(tmp3,tmp4);
	cout<<(l1+l2)<<"\n";
	return 0;
}