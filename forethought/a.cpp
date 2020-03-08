#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a')cnt++;
	}
	if(2*cnt>s.size()){cout<<s.size()<<"\n";}
	else{
		int ans=s.size();
		while(2*cnt<ans)ans--;
		if(ans==2*cnt)ans--;
		cout<<ans<<"\n";
	}
	return 0;
}