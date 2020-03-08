#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
int main(){
	int n;cin>>n;
	int f[1000004];f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=1e7;
		int tmp=i;
		while(tmp){
			f[i]=min(f[i],1+f[i-tmp%10]);
			tmp/=10;
		}
	}
	cout<<f[n]<<"\n";
	return 0;
}
