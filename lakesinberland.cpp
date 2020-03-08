#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
char s[100][100];
int vis[100][100];
int n,m;
queue<pair<int,int> > q;
void modify(int row,int col){
	q.push(mp(row,col));
	while(!q.empty()){
		pair<int,int>p=q.front();
		q.pop();
		s[p.f][p.s]='*';
		if(p.f+1<n  && (s[p.f+1][p.s]=='.')){q.push(mp(p.f+1,p.s));}
		if(p.f-1>=0 && (s[p.f-1][p.s]=='.')){q.push(mp(p.f-1,p.s));}
		if(p.s+1<m &&  (s[p.f][p.s+1]=='.')){q.push(mp(p.f,p.s+1));}
		if(p.s-1>=0 && (s[p.f][p.s-1]=='.')){q.push(mp(p.f,p.s-1));}
	}
	return ;
}
pair<int,pair<int,int> >bfs(int row,int col,int& res){
	q.push(mp(row,col));
	int sz=0;
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		if(vis[p.f][p.s])continue;
		vis[p.f][p.s]=1;sz++;
		if((p.f+1==n) || (p.f==0 )|| (p.s ==0) || (p.s==(m-1))){res=0;}
		if(p.f+1<n && (vis[p.f+1][p.s]==0) && (s[p.f+1][p.s]=='.')){q.push(mp(p.f+1,p.s));}
		if(p.f-1>=0 && vis[p.f-1][p.s]==0 && s[p.f-1][p.s]=='.'){q.push(mp(p.f-1,p.s));}
		if(p.s+1<m && vis[p.f][p.s+1]==0 && s[p.f][p.s+1]=='.'){q.push(mp(p.f,p.s+1));}
		if(p.s-1>=0 && vis[p.f][p.s-1]==0 && s[p.f][p.s-1]=='.'){q.push(mp(p.f,p.s-1));}
	}
	pair<int,pair<int,int> > rt=mp(sz,mp(row,col));
	return rt;
}
int main(){
	int k;cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	int tmp=0;
	set<pair<int,pair<int,int> > > st;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='*' || vis[i][j])continue;
			int flg=1;
			//cout<<"i= "<<i<<"j= "<<j<<" flg= "<<flg<<"\n";
			pair<int,pair<int,int> > p=bfs(i,j,flg);
			if(flg){st.insert(mp(p.f,mp(p.s.f,p.s.s)));tmp++;}
		}
	}
	int ans=0;
	while(tmp>k){
		pair<int,pair<int,int> > p= *st.begin();
		st.erase(p);
		tmp--;ans+=p.f;
		modify(p.s.f,p.s.s);
	}
	cout<<ans<<"\n";
	for(int i=0;i<n;i++)cout<<s[i]<<"\n";
	return 0;
}