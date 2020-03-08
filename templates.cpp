#include<bits/stdc++.h>
using namespace std;
template<class T,class Z> T add(T a,Z b){
	return a+b;
} 
template<class T>
class A{
	public:
		T add_num(T a,T b){
			return a+b;
		}
};
int main(){
	cout<<add(4,6)<<endl;
	cout<<add(5.8,6)<<endl;
	A<float> obj;
	cout<<obj.add_num(5.0,10.1)<<endl;
	return 0;
}