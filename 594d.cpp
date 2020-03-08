#include<bits/stdc++.h>
using namespace std;
int sum[100002];
//vector<int>neg;
int main(){
	int n;cin>>n;
	string s;cin>>s;
	int neg=0;
	int tmp=0;
	int l=-1,r=-1;
	int zero=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='(')tmp++;
		else tmp--;
		//sum[i]+=sum[i-1];
		if(tmp<0){
			if(l==-1)l=i;
			//else if(r==-1)continue;
			//else neg.push_back(i);
		}
		if(l!=-1 && tmp>=0 &&  r==-1)r=i;
		//if(sum[i]<0)neg.push_back(i);
	}
	if(tmp!=0){cout<<"0\n"<<"1 1\n";return 0;}
	if(l!=-1 && r!=-1)swap(s[l-1],s[r-1]);
	int minn=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='(')sum[i]++;
		else sum[i]--;
		sum[i]+=sum[i-1];
		if(sum[i]<minn){
			minn=sum[i];cnt=1;
		}
		else if(sum[i]==minn)cnt++;
	}
	//cout<<"zer0= "<<zero<<"\n"
	cout<<cnt<<"\n";
	if(l==-1 || r==-1){l=1;r=1;}
	cout<<l<<" "<<r<<"\n";
	return 0;

}