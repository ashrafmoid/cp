#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
char mat[1002][1002];
int vis[1002][1002];
int main(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	int r,c;cin>>r>>c;
	int st_i,st_j,en_i,en_j;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='E'){en_i=i;en_j=j;}
			if(mat[i][j]=='S'){st_i=i;st_j=j;}
		}
	}
	queue<pair<pair<int,int>,int> > q;
	q.push(mp(mp(st_i,st_j),0));
	int res=0;
	while(!q.empty()){
		pair<int,int> p=q.front().f;
		int tmp=q.front().s;
		q.pop();
		//cout<<"x= "<<p.f<<" y= "<<p.s<<"\n";
		if(p==mp(en_i,en_j)){res=tmp;break;}
		if(vis[p.f][p.s])continue;
		vis[p.f][p.s]=1;
		if(p.f-1>=0 && vis[p.f-1][p.s]==0 && mat[p.f-1][p.s]!='T'){
			q.push(mp(mp(p.f-1,p.s),tmp+1));
		}
		if(p.s-1>=0 && vis[p.f][p.s-1]==0 && mat[p.f][p.s-1]!='T'){
			q.push(mp(mp(p.f,p.s-1),tmp+1));
		}
		if(p.f+1<r && vis[p.f+1][p.s]==0 && mat[p.f+1][p.s]!='T'){
			q.push(mp(mp(p.f+1,p.s),tmp+1));
		}
		if(p.s+1<c && vis[p.f][p.s+1]==0 && mat[p.f][p.s+1]!='T'){
			q.push(mp(mp(p.f,p.s+1),tmp+1));
		}
	}
	//cout<<"res= "<<res<<"\n";
	while(!q.empty())q.pop();
	for(int i=0;i<r;i++)for(int j=0;j<c;j++)vis[i][j]=0;
	q.push(mp(mp(en_i,en_j),0));
	int ans=0;
	while(!q.empty()){
		pair<int,int> p=q.front().f;
		int tmp=q.front().s;
		q.pop();
		if(vis[p.f][p.s])continue;
		vis[p.f][p.s]=1;
		if(tmp<=res){
			if(mat[p.f][p.s]!='S' && mat[p.f][p.s]!='E')ans+=mat[p.f][p.s]-'0';
		}
		//if(p==mp(en_i,en_j)){res=tmp;break;}
		if(p.f-1>=0 && vis[p.f-1][p.s]==0 && mat[p.f-1][p.s]!='T'){
			q.push(mp(mp(p.f-1,p.s),tmp+1));
		}
		if(p.s-1>=0 && vis[p.f][p.s-1]==0 && mat[p.f][p.s-1]!='T'){
			q.push(mp(mp(p.f,p.s-1),tmp+1));
		}
		if(p.f+1<r && vis[p.f+1][p.s]==0 && mat[p.f+1][p.s]!='T'){
			q.push(mp(mp(p.f+1,p.s),tmp+1));
		}
		if(p.s+1<c && vis[p.f][p.s+1]==0 && mat[p.f][p.s+1]!='T'){
			q.push(mp(mp(p.f,p.s+1),tmp+1));
		}
	}
	cout<<ans<<"\n";
	return 0;

}