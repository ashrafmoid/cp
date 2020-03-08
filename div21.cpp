#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
string t;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	string s;cin>>s;
	t="ACTG";
	int ans=9999;
	for(int i=0;i+3<n;i++){
		int tmp=0;
		for(int j=0;j<4;j++){
			int v1=s[i+j]-'A';
			int v2=t[j]-'A';
			int minn=999;minn=min(minn,abs(v1-v2));
			if(v1<v2)minn=min(minn,v1+25-v2+1);if(v1>v2)minn=min(25-v1+v2+1,minn);
			tmp+=minn;
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}