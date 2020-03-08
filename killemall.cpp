#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	vector<int>v1,v2;
	while(q--){
		int n,r;cin>>n>>r;
		v1.clear();v2.clear();
		//v1.push_back(-1);
		for(int i=0;i<n;i++){
			int x;cin>>x;v1.push_back(x);
		}
		sort(v1.begin(),v1.end());
		v2.push_back(-1);
		for(int i=0;i<n;){
			int j=i+1;
			v2.push_back(v1[i]);
			while(j<n&&v1[j]==v1[i])j++;
			i=j;
		}
		int ans=0;
		int lo=1,hi=v2.size()-1;
		n=hi;
		//cout<<"hi= "<<hi<<"\n";
		while(lo<=hi){
			int mid=(lo+hi)/2;
			//cout<<"mid= "<<mid<<"rmid= "<<r*mid<<"vmid= "<<v2[n-mid]<<"\n";
			if(r*mid >= v2[n-mid]){ans=mid;hi=mid-1;}
			else lo=mid+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}