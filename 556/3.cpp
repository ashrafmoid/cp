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
	int n;cin>>n;
	int ons=0,tws=0;
	int x;
	for(int i=0;i<n;i++){cin>>x;if(x==1)ons++;else tws++;}
	if(tws){cout<<"2 ";tws--;}
	if(ons){cout<<"1 ";ons--;}
	while(tws || ons ){
		if(tws){cout<<"2 ";tws--;}
		else if(ons){cout<<"1 ";ons--;}
	}
	cout<<"\n";
	return 0;
}