#include<bits/stdc++.h>
using namespace std;
int f[8004];
int cmp(int x,int y){
	return x>y;
}
//vector<int> dif;
typedef long long ll;
int main(){
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;cin>>x;f[x]++;
	}
	ll ans=1e18;
	set<int>dif;
	vector<int>num;
	for(int i=1;i<=k;i++)if(f[i]){num.push_back(f[i]);}//cout<<"i= "<<i<<"\n";}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++){
		dif.insert(num[i]);
	}
	dif.insert(2*num[0]);
	multiset<int> mst;

	for(int i=num[0];i<=num[1]+num[0] && !dif.empty();){
		mst.clear();
		//cout<<"hmm\n";
		ll tmp=0;
		for(int j=0;j<num.size();j++)mst.insert(num[j]);
		while(!mst.empty()){
			int x= *(--mst.end());
			//cout<<"x= "<<x<<"\n";
			mst.erase(--mst.end());
			tmp+=i;
			if(mst.empty())break;
			auto it = mst.lower_bound(i-x);
			if(*it==i-x)mst.erase(it);
			else if(it==mst.begin())continue;
			else (mst.erase(--it));
		}
		ans=min(ans,tmp);
		//if(dif.empty() && i<num[0]+num[1])i=num[0]+num[1];
		if(dif.empty())break;
		//else if(dif.empty())break;
		i=num[0]+ (*(dif.begin()));
		dif.erase(dif.begin());
	}
	cout<<ans<<"\n";
	return 0;
}