#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,r;cin>>n>>m>>r;
	int s[50],b[50];
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(s,s+n);
	sort(b,b+m);
	if(s[0]>=b[m-1]){cout<<r<<"\n";return 0;}
	int tmp=(r/s[0]);
	r-=tmp*s[0];
	r+=tmp*b[m-1];
	cout<<r<<"\n";
	return 0;	
}