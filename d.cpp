#include<bits/stdc++.h>
using namespace std;
//int a[10002];
int lft[200001],rght[200001];
int h[200001];
int main(){
	//set<pair<int,int> >st;
	 ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	string s1,s2;cin>>s1>>s2;
	memset(h,-1,sizeof(h));
	memset(lft,0,sizeof(lft));
	memset(rght,0,sizeof(rght));
	int lo=0;
	for(int i=0;i<s1.size();i++){
		if(lo==s2.size()){lft[i]=lft[i-1];continue;}
		if(i)lft[i]=lft[i-1];
		if(s1[i]==s2[lo]){lft[i]++;lo++;}
	}
	int hi=s2.size()-1;
	for(int i=s1.size()-1;i>=0;i--){
		if(hi<0){rght[i]=rght[i+1];continue;}
		if(i<s1.size()-1)rght[i]=rght[i+1];
		if(s1[i]==s2[hi]){rght[i]++;hi--;}
	}
	int ans=0;
	for(int i=0;i<s1.size();i++){
		h[rght[i]]=i;
		if(rght[i]>=(int)s2.size())ans=max(ans,i);
	}
	for(int i=0;i<s1.size();i++){
		int v1=lft[i];
		int req=s2.size()-v1;
		if(req<=0)ans=max(ans,(int)s1.size()-i-1);
		else if(h[req]!=-1){
			ans=max(ans,h[req]-i-1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
