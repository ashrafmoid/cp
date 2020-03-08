#include<bits/stdc++.h>
using namespace std;
string getstring(string source,int indx){
	string tmp="";
	for(int i=0;i<source.size();i++){
		if(i==indx)continue;
		tmp+=source[i];
	}
	return tmp;
}
int main(){
	unordered_map<string,int> mp;
	int n,k;cin>>n>>k;
	string s;cin>>s;
	queue<pair<string,int> > q;
	q.push(make_pair(s,0));
	int cst=0;
	while(!q.empty()&&k){
		pair<string,int> p=q.front();q.pop();
		if(mp.find(p.first)==mp.end())mp[p.first]=1;
		else continue;
		k--;cst+=p.second;
		for(int i=0;i<p.first.size();i++){
			string tmp=getstring(p.first,i);
			if(mp.find(tmp)==mp.end()){
				q.push(make_pair(tmp,p.second+1));
			}
		}
	}
	if(k){cout<<"-1\n";return 0;}
	cout<<cst<<"\n";
	return 0;
}