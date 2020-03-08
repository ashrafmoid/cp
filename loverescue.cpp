#include<bits/stdc++.h>
using namespace std;
int mat[30][30];
//set<int> st;
int a[30];
int vis[30];
vector<int >ans[30];
int k=0;
char color[30];
char mp[30];
int dfs(int root,int prnt){
	if(vis[root]||color[root]!='w')return 0;
	int cnt=1;
	vis[root]=1;
	color[root]='g';
	ans[k].push_back(root);
	for(int i=0;i<26;i++){
		if(mat[root][i]&&color[i]=='w'){
			cnt+=dfs(i,root);
		}
	}
	color[root]='b';
	return cnt;

}
int main(){
	 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tmp=0;
  for(char i='a';i<='z';i++ )mp[tmp++]=i;
  for(int i=0;i<30;i++)color[i]='w';
  int n;cin>>n;
  string s1,s2;cin>>s1>>s2;
  for(int i=0;i<n;i++){
  	if(s1[i]==s2[i])continue;
  	mat[s1[i]-'a'][s2[i]-'a']=1;
  	mat[s2[i]-'a'][s1[i]-'a']=1;
  	a[s1[i]-'a']=1;a[s2[i]-'a']=1;
  }
  int res=0;
  for(int i=0;i<26;i++){
  	if(a[i]==0 || vis[i])continue;
  	res+=dfs(i,i)-1;
  	//cout<<"i= "<<i<<" res= "<<res<<"\n";
  	k++;
  }
  cout<<res<<"\n";
  for(int i=0;i<k;i++){
  	for(int j=0;j<ans[i].size()-1;j++){cout<<mp[ans[i][j]]<<" "<<mp[ans[i][j+1]]<<"\n";}
  	cout<<"\n";
  }
  return 0;
}