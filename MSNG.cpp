#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,int> mp;
ll getval(ll base,string s){
	ll res=0;
	//cout<<s<<"\n";
	//ll pwr=1ll;
	for(int i=0;i<s.size();i++){
		res=res*base+mp[s[i]];
		//pwr*=base;
		//cout<<res<<" ";
		if(res>1e12)return res;
	}
	//cout<<"\n";
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	int tmp=0;
	for(char a='0';a<='9';a++)mp[a]=tmp++;
	for(char a='A';a<='Z';a++)mp[a]=tmp++;
	int t;cin>>t;
	vector<ll> v[100];
	string s;
	ll final_val=0;int cnt;
	while(t--){
		//int j=0;
		tmp=0;
		final_val=-1,cnt=0;
		int n;cin>>n;
		for(int i=0;i<n;i++)v[i].clear();
		for(int i=0;i<n;i++){
			int b;cin>>b>>s;
			if(b==-1){
				int minn=-1;
				for(int j=0;j<s.size();j++)minn=max(minn,mp[s[j]]);
				//cout<<"minn= "<<minn<<"\n";
				for(int j=minn+1;j<37;j++){
					//cout<<"getval= "<<getval(j,s)<<"\n";
					v[tmp].push_back(getval(j,s));
				}
				tmp++;
			}
			else{
				//flg=1;
				if(final_val==-1){final_val=getval(b,s);cnt++;}
				else if(final_val!=getval(b,s))cnt++;
				//cout<<"final value= "<<getval(b,s)<<"\n";
			}
		}
		if(cnt>1){cout<<"-1\n";}
		else if(cnt==1){
			int flg=0;
			if(final_val>1e12){cout<<"-1\n";continue;}
			for(int j=0;j<tmp;j++){
				if(final_val== (*lower_bound(v[j].begin(),v[j].end(),final_val)))flg++;
			}
			//cout<<"flg= "<<flg<<"\n";
			if(flg==tmp)cout<<final_val<<"\n";
			else cout<<"-1\n";
		}
		else {
			if(tmp==1){
				if(v[0][0]<1e12){cout<<v[0][0]<<"\n";continue;}
				else cout<<"-1\n";
				continue;
			}
			int cnt=0;ll val=-1;
			for(int i=0;i<v[0].size();i++){
				if(v[0][i]>1e12)break;
				cnt=0;
				for(int j=1;j<tmp;j++){
					if(v[0][i]==(*lower_bound(v[j].begin(),v[j].end(),v[0][i])))cnt++;
				}
				if(cnt==tmp-1){
					val=v[0][i];
					break;
				}
			}
			if(cnt==tmp-1)cout<<val<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}