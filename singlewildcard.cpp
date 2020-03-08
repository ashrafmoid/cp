#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	string lft="",rht="";
	int mid=n-1;
	int flg=0;
	for(int i=0;i<n;i++){
		if(s[i]!='*')lft+=s[i];
		else {mid=i;flg=1;break;}
	}
	for(int i=mid+1;i<n;i++){
		rht+=s[i];
	}
	int len1=lft.size();int len2=rht.size();
	int lft_indx=0,rht_indx=m-1;
	int i=0;
	while(i<len1 && lft_indx <m && lft[i]==t[lft_indx]){
		lft_indx++;i++;
	}
	if(i!=len1){cout<<"NO\n";return 0;}
	i=len2-1;
	lft_indx--;
	while(i>=0 && rht_indx>=0 && rht[i]==t[rht_indx]){
		rht_indx--;i--;
	}
	if(i>=0){cout<<"NO\n";return 0;}
	rht_indx++;
	if(lft_indx>=rht_indx){cout<<"NO\n";return 0;}
	//if((lft.empty() || rht.empty()) && lft_indx+1 != rht_indx){cout<<"NO\n";return 0;}
	if(!flg && lft_indx+1 != rht_indx){
		cout<<"NO\n";return 0;
	}
	cout<<"YES\n";
	return 0;
}