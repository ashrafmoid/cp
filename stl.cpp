#include<bits/stdc++.h>
using namespace std;
// struct smaller{
// 	bool operator()(int& x,int&  y){
// 		return x>=y;
// 	}
// };
bool smaller(int x,int y){
	return x>=y;
}
int main(){
	vector<int> a={1,2,3,4,5};
	partial_sum(a.begin(),a.end(),a.begin());
	//make_heap(a.begin(),a.end(),smaller);
	for(int i=0;i<5;i++)cout<<a[i]<<" ";
	cout<<"\n";
	cout<<is_sorted(a.begin(),a.end())<<"\n";
	a.push_back(0);
	cout<<"size= "<<a.size()<<"\n";
	push_heap(a.begin(),a.end(),smaller);
	pop_heap(a.begin(),a.end(),smaller);
	cout<<a.front()<<"\n";
	a.pop_back();
	for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}