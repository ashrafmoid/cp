#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
ll mod=1e9+7;
int bit[26][200002];
void update(int x,int val,int n,int pos){
	for(;x<=n;x+=x&-x)bit[pos][x]+=val;
		return ;
}
int query(int x,int pos){
	int res=0;
	for(;x>0;x-=x&-x)res+=bit[pos][x];
		return res;
}

int main(){
	ios_base::sync_with_stdio(false);	
	  cin.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		int pos=s[i]-'a';
		update(i+1,1,n,pos);
	}
	int q;cin>>q;
	while(q--){
		int op;cin>>op;
		if(op==1){
			int pos;char c;cin>>pos>>c;
			int tmp=s[pos-1]-'a';
			update(pos,-1,n,tmp);
			update(pos,1,n,c-'a');
			s[pos-1]=c;
		}
		else{
			int l,r;cin>>l>>r;
			int ans=0;
			for(int i=0;i<26;i++){
				if(query(r,i)-query(l-1,i)>0)ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}