#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[106];
	int x;char ch;
	int i=0;
	//cout<<a[i-1]<<"\n";
	for (;scanf("%d%c",&x,&ch)==2&&ch==',';) {a[i]=x;i++;}
	a[i++]=x;
	sort(a,a+i);
	//for(int j=0;j<i;j++)cout<<"a[i]="<<a[j]<<"\n";
	int start=0,end=0;
	int flg=0;
	while(end<i){
		int j=start;end++;
		while(end<i&&(a[end]==a[j]||a[end]==a[j]+1))end++,j++;
		if(flg==1)cout<<",";
		cout<<a[start];
		if(abs(a[end-1]-a[start])!=0)cout<<"-"<<a[end-1];
		if(flg==0)flg=1;
		//cout<<"start="<<start<<"end= "<<end<<"\n";
		start=end;
	}
	return 0;
}