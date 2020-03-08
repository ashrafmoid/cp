#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
int main(){
	string s,t;
	cin>>s>>t;
	vector<pair<int,int> > ans;
	int pot=0;
	int n,m;n=s.size();m=t.size();
	bool flg=true;
	for(;pot<m;){
		int l=-1,r=-1;
		for(int i=0;i<n;i++){
			if(s[i]!=t[pot])continue;
			int j=i,tmp=pot;
			while(j<n && tmp<m && s[j]==t[tmp]){j++;tmp++;}
			j--;tmp--;
			if(j-i>=abs(r-l)){l=i;r=j;}
			j=i;tmp=pot;
			while(j>=0 && tmp<m && s[j]==t[tmp]){j--;tmp++;}
			j++;tmp--;
			if(i-j>=abs(r-l)){l=i;r=j;}
		}
		if(l==-1){flg=false;break;}
		ans.push_back(mp(l+1,r+1));
		pot+=abs(r-l)+1;
	}
	if(flg){
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++)cout<<ans[i].f<<" "<<ans[i].s<<"\n";
	}
	else cout<<"-1\n";
	return 0;
}