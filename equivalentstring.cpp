#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
//#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL)
string s1,s2;
bool eql(int lo1,int hi1,int lo2,int hi2){
	if(lo1>hi1 || lo2>hi2)return 1;
	int flg=1;
	int i=lo1,j=lo2;
	while(i<=hi1 && j<= hi2){
		if(s1[i]!=s2[j]){flg=0;break;}
		i++;j++;
	}
	return flg;
}
bool chck(int lo1,int hi1,int lo2,int hi2){
	int mid1=(lo1+hi1)/2;
	int mid2=(lo2+hi2)/2;
	int len=(hi1-lo1+1);
	//int flg=eql(lo1,hi1,lo2,hi2);
	//printf("lo1= %d,lo2=%d,hi1=%d,hi2=%d,flg=%d\n",lo1,lo2,hi1,hi2,flg);
	//if(flg)return flg;
	if(len%2==1){
		int flg=eql(lo1,hi1,lo2,hi2);
		return flg;
	}
	int f1=(chck(lo1,mid1,lo2,mid2)&&chck(mid1+1,hi1,mid2+1,hi2) );
	if(f1)return f1;
	int f2=(chck(lo1,mid1,mid2+1,hi2)&&chck(mid1+1,hi1,lo2,mid2));
	return f2;
	//return ((chck(lo1,mid1,lo2,mid2)&&chck(mid1+1,hi1,mid2+1,hi2) )||(chck(lo1,mid1,mid2+1,hi2)&&chck(mid1+1,hi1,lo2,mid2)) );
}
int main(){
	//fast_io;
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	if(chck(0,len1-1,0,len2-1)){cout<<"YES\n";}
	else cout<<"NO\n";
	return 0;
}