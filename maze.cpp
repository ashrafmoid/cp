#include<bits/stdc++.h>
using namespace std;
//int cnt[505][505];
int visit[505][505];
char s[505][505];
int n,m,k;
void dfs(int x,int y){
	if(x<0 || x> n || y<0 || y>m || s[x][y]!='.' || visit[x][y] )return;
	visit[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);dfs(x,y-1);
	if(k){s[x][y]='X';k--;}
	return;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	vector<pair<int,int> >ans;
	//queue<pair<int,int> >q;
	pair<int,int> strt;
	int fre=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='.')fre++;
	int flg=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(s[i][j]=='.'){
			strt=make_pair(i,j);
			flg=1;
			break;
		}
		if(flg)break;
	}
	dfs(strt.first,strt.second);
	//int cnt=0;
	//stack<pair<int,int> >bfs;
	for(int i=0;i<n;i++)cout<<s[i]<<"\n";
	return 0;
}