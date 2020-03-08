#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	int dgr[100001];
	while(t--){
		int n,m;cin>>n>>m;
		int u,v;
		for(int i=0;i<n;i++)dgr[i]=0;
		for(int i=0;i<m;i++){cin>>u>>v;u--;v--;dgr[u]++;dgr[v]++;}
		if(m%2==0){cout<<"1\n";
			for(int i=0;i<n;i++)cout<<"1 ";
			cout<<"\n";
			continue;
		}
		int odd_dgr=-1;
		for(int i=0;i<n;i++){
			if(dgr[i]%2){odd_dgr=i;break;}
		}
		if(odd_dgr!=-1){
			cout<<"2\n";
			for(int i=0;i<n;i++){
				if(odd_dgr==i)cout<<"2 ";
				else cout<<"1 ";
			}
			cout<<"\n";
			continue;
		}
		cout<<"3\n";
		for(int i=0;i<n;i++){
			if(i!=u && i!=v)cout<<"1 ";
			else if(i==u)cout<<"2 ";
			else cout<<"3 ";
		}
		cout<<"\n";
	}
	return 0;
}