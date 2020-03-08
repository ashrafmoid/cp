#include<bits/stdc++.h>
using namespace std;
int chck[45][45];
int tot[45][45][45][45];
int main(){
	int n,m,q;cin>>n>>m>>q;
	char s[45][45];
	// /for(int i=1;i<n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>s[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='0')chck[i][j]=chck[i][j-1]+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int x=i;x<=n;x++){
				for(int y=j;y<=m;y++){
					tot[i][j][x][y]=tot[i][j][x-1][y]+tot[i][j][x][y-1]-tot[i][j][x-1][y-1];		
					int w=y-j+1;
					int t=x;
					while(t>=i){
						tot[i][j][x][y]+=min(w,chck[t][y]);
						w=min(w,chck[t][y]);
						t--;
					}
				}
			}
		}
	}
	//for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<tot[i][j];cout<<"\n";}
		for(int i=0;i<q;i++){
			int a,b,c,d;cin>>a>>b>>c>>d;
			//a--;b--;c--;d--;
			int ans=tot[a][b][c][d];
			// if(a-1>=0)ans-=tot[a-1][d];
			// if(b-1>=0)ans-=tot[c][b-1];
			// if(a-1>=0 && b-1>=0)ans+=tot[a-1][b-1];
			cout<<ans<<"\n";
		}
	return 0;
}