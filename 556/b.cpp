	#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
char s[55][55];
int vis[55][55];
int n;
int chck(int r,int c){
	if(r<0 || c<0 || r>=n || c>=n)return 0;
	if(s[r][c]=='.')return 1;
	return 0; 
}
void mark_p(int r,int c){
	if(chck(r,c))s[r][c]='#';
	if(chck(r+1,c))s[r+1][c]='#';
	if(chck(r-1,c))s[r-1][c]='#';
	if(chck(r,c+1))s[r][c+1]='#';
	if(chck(r,c-1))s[r][c-1]='#';
	return ;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='#')continue;
			//if(vis[i][j])continue;
			int flg=1;
			flg=chck(i+1,j)&&chck(i-1,j)&&chck(i,j+1)&&chck(i,j-1)&&chck(i,j);
			if(flg){mark_p(i,j);}
			//if(flg)
			//cout<<"i= "<<i<<"j= "<<j;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(s[i][j]=='.'){cout<<"NO\n";return 0;}
	cout<<"YES\n";
return 0;
}