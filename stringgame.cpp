#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int m=s2.size();
	int p[200005];
	for(int i=0;i<n;i++){
		int x;cin>>x;
		p[x-1]=i;
	}
	int lo=0,hi=n-1;
	int ans=-1;
	while(hi>=lo){
		int mid=(hi+lo)/2;
		int j=0;
		for(int i=0;i<n && j<m;i++){
			if(p[i]<=mid)continue;
			if(s1[i]==s2[j])j++;
		}
		if(j==m){ans=mid;lo=mid+1;}
		else hi=mid-1;
	}
	cout<<(ans+1)<<"\n";
	return 0;
}