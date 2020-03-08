#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
int b[305];
int a[605];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,j=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int l=b[i]-b[i-1];
		if(l<=0){
			l= -l+1;x=0;
			for(j=600;j>=0;j--){if(x<l | a[j]==9)x+=a[j],a[j]=0;else break;}
				l=x-l;a[j]++;
		}
		for(j=600;j>=0;j--){
			x=min(a[j]+l,9);l-=(x-a[j]);a[j]=x;
		}
		j=0;while(!a[j])j++;
		for(;j<=600;j++)cout<<a[j];
			cout<<"\n";

	}
	return 0;
}