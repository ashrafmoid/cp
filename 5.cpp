#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
ll mod=1e9+7;
class mycomparison
{
public:
	bool operator()(const pair<int,int>& p1,const pair<int,int>& p2)const{
		return p1.f > p2.f;
	}
};
class mycomparison2
{
public:
	bool operator()(pair<int,int> p1,pair<int,int> p2){
		return p1.f < p2.f;
	}
};
int main(){
	int n,k;cin>>n>>k;
	int a[200005];
	int ans[200005];
	//priority_queue<pair<int,int>,vector<pair<int,int> >,mycomparison> pq;
	set<pair<int,int>,mycomparison>pq;
	set<pair<int,int>,mycomparison2>pq1;
	for(int i=1;i<=n;i++){cin>>a[i];pq.insert(mp(a[i],i));pq1.insert(mp(i,a[i]));}
	//cout<<(pq1.begin()->f)<<"\n";
	int x=n;
	int op=1;
	while(x){
		pair<int,int> p=*pq.begin();
		int indx=p.s;ans[indx]=op;
		pq.erase(mp(a[indx],indx));
		pq1.erase(mp(indx,a[indx]));
		cout<<(p.s)<<" ";
		//int tmp=0;
		x--;
		int tmp=indx,z=0;
		while(z<k && pq1.lower_bound(mp(tmp,-1))!=pq1.end() ){
			p = *pq1.lower_bound(mp(tmp,-1));
			cout<<(p.f)<<" ";
			z++;ans[p.f]=op;//tmp=p.f;
			pq.erase(mp(p.s,p.f));
			pq1.erase(mp(p.f,p.s));
			x--;
		}
		z=0;tmp=indx;
		while(z<k && pq1.upper_bound(mp(tmp,-1))!=pq1.begin()){
			p=*pq1.upper_bound(mp(tmp,-1));
			cout<<(p.f)<<" ";
			z++;ans[p.f]=op;//tmp=p.f;
			pq.erase(mp(p.s,p.f));
			pq1.erase(mp(p.f,p.s));
			x--;
		}
		cout<<"yy\n";
		// for(int i=indx+1;tmp<k && indx<=n;tmp++,i++){
		// 	ans[i]=op;pq.erase(mp(a[i],i));x--;
		// }
		// for(int i=indx-1,tmp=0;tmp<k && i>=1;i--,tmp++){
		// 	ans[i]=op;pq.erase(mp(a[i],i));x--;
		// }
		if(op==1)op=2;
		else op=1;
		//pq.po
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
		return 0;
	
}