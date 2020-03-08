#include<bits/stdc++.h>
using namespace std;
//vector<int> v[52];
int mat[52][10004];
int main(){
	int m,n;cin>>m>>n;
	for(int i=0;i<m;i++){
		int t;cin>>t;
		for(int j=0;j<t;j++){
			int x;cin>>x;mat[i][x]=1;
			//v[i].push_back(x);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j)continue;
			int cnt=0;
			for(int k=1;k<=n;k++){if(mat[i][k] && mat[j][k])cnt++;}
			if(cnt==0){cout<<"impossible\n";return 0;}
		}
	}
	cout<<"possible\n";
	return 0;
}