#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200003];
ll b[200003];
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	set<pair<int,int> >st;
	for(int i=0;i<m;i++){
		int t,r;cin>>t>>r;
		while(!st.empty()&&(*st.begin()).first<=r){st.erase(st.begin());}
		st.insert(make_pair(r,t));
	}
	int indx=(*st.rbegin()).first;
	int start=0,end=indx-1;
	sort(a,a+indx);
	int j=n-1;
	while(j>indx-1){
		b[j]=a[j];j--;
	}
	while(!st.empty()){
		int indx1=(*st.rbegin()).first;
		int typ=(*st.rbegin()).second;
		st.erase(--st.end());
		int indx2=0;
		if(!st.empty()){
			indx2=(*st.rbegin()).first;
		}
		if(typ==1){
			for(int k=0;k<indx1-indx2;k++){
				b[j--]=a[end--];
			}	
		}
		else{
			for(int k=0;k<indx1-indx2;k++){
				b[j--]=a[start++];
			}
		}
	}
	for(int i=0;i<n;i++)cout<<b[i]<<" ";
		return 0;
}