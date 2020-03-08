#include<bits/stdc++.h>
using namespace std;
int f[12];
int tmp[12];
void print_num(){
	int flg=0;
	for(int i=9;i>0;i--){if(tmp[i]){flg=1;break;}}
		if(flg==0){cout<<"0\n";return ;}
	for(int i=9;i>=0;i--)while(tmp[i]){cout<<i;tmp[i]--;}
		return;
}
int main(){
	int n;cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;f[x]++;
		tmp[x]++;
		sum+=x;
	}
	if(f[0]==0){cout<<"-1\n";return 0;}
	if(sum==0){cout<<"0\n";return 0;}
	f[0]--;
	//cout<<sum<<"\n";
	int b[3][3];
	int cnt[3];for(int i=0;i<3;i++)cnt[i]=0;
	for(int i=0;i<10;i++){
		while(cnt[i%3]<3&&f[i]){
			b[i%3][cnt[i%3]]=i;
			f[i]--;cnt[i%3]++;
		}
	}
	if(sum%3==0){
		//cout<<"--->"<<(sum%3)<<"\n";
		// if(cnt[0]!=0){
		// 	//cout<<b[0][0]<<"\n";
		// 	tmp[b[0][0]]--;
		// }
		// else if(cnt[1]>0 &&cnt[2]>0){
		// 	tmp[b[1][0]]--;tmp[b[2][0]]--;
		// 	//cout<<"2\n";
		// }
		// else if(cnt[1]==3){
		// 	//cout<<"3\n";
		// 	for(int i=0;i<3;i++)tmp[b[1][i]]--;
		// }
		// else if(cnt[2]==3){
		// 	//cout<<"4\n";
		// 	for(int i=0;i<3;i++)tmp[b[2][i]]--;
		// }
		// else {cout<<"-1\n";return 0;}
		print_num();
	}
	else if(sum%3==1){
		//cout<<"--->"<<(sum%3)<<"\n";
		if(cnt[1]!=0){
			tmp[b[1][0]]--;
		}
		else if(cnt[2]>1){tmp[b[2][0]]--;tmp[b[2][1]]--;}
		else {cout<<"-1\n";return 0;}
		print_num();
	}
	else{
		//cout<<"--->"<<(sum%3)<<"\n";
		if(cnt[2]!=0){
			tmp[b[2][0]]--;
		}
		else if(cnt[1]>1){tmp[b[1][0]]--;tmp[b[1][1]]--;}
		else {cout<<"-1\n";return 0;}
		print_num();
	}
	return 0;

}