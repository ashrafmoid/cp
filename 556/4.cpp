#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
set<pair<int,int> > crnt[3];
set<pair<int,int> > rqwst[3];
int main(){
	string st="";
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int n,q;cin>>n>>q;
	set<int> s[30];
	for(int i=0;i<n;i++){
		char x;cin>>x;s[x-'a'].insert(i);
		st+=x;

	}
	int cnt_time=200000;
	for(int i=0;i<q;i++){
		char x;int t;cin>>x>>t;t--;
		if(x=='-'){
			auto it1=crnt[t].end();
			if(!crnt[t].empty())it1--;
			auto it2=rqwst[t].end();
			if(!rqwst[t].empty())it2--;
			if(it1==crnt[t].end() && it2==rqwst[t].end()){continue;}
			else if(it1==crnt[t].end()){
				rqwst[t].erase(it2);
			}
			else if(it2==rqwst[t].end()){
				crnt[t].erase(it1);
				auto its1,its2;
				int flag1=0,flag2;
				for(int j=0;j<3;j++){
					if(j==t)continue;
					its1=rqwst[j].lower_bound(mp(st[it->s],-1));
					flag1=j;
					break;
				}
				for(int j=0;j<3;j++){
					if(j==t || j==flag)continue;
					its2=rqwst[j].lower_bound(mp(st[it->s],-1));
					flag2=j;
					break;
				}
				if(its1!=rqwst[flag1].end()){
					rqwst[flag1].erase(its1);
					crnt[flag1].insert(mp());
				}

			}
			else{

			}
		}
		else{
			char z;cin>>z;
			auto it=s[z-'a'].begin();
			if(it==s[z-'a'].end()){
				rqwst[t].insert(mp(z,cnt_time--));
			}
			else{
				crnt[t].insert(mp(cnt_time--,*it));
				s[z-'a'].erase(it);
			}
		}
		int flg=0;
		for(int j=0;j<3;j++){
			if(rqwst[j].empty())flg=1;
		}
		if(flg){cout<<"NO\n";}
		else cout<<"YES\n";
	}
	return 0;
}