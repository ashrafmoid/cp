#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;cin>>n;
	int l[n+1];
	for(int i=0;i<n;i++)cin>>l[i];
	sort(l,l+n);
	int i=n-2;
	int maxx1=0,maxx2=0;
	long long int ans=0;
	while(i>=0){
		if(abs(l[i]-l[i+1])<=1){
			//cout<<"uoo\n";
			if(maxx1==0)maxx1=min(l[i],l[i+1]);
			else if(maxx2==0){maxx2=min(l[i],l[i+1]);
				ans+=(1ll*maxx2*maxx1);
				maxx2=maxx1=0;
			}
			i--;
		}
		i--;
	}
	cout<<ans<<"\n";
	return 0;
}