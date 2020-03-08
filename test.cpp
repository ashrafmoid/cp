#include<bits/stdc++.h>
using namespace std;
class A{
public:
	// void fun(){
	// 	cout<<"IN a";
	// }
	void fun(int i){
		cout<<"Overloaded\n";
	}
};
class B:A{
public:
	void fun(){
		cout<<"IN B";
	}
	// void fun(int i){
	// 	cout<<"Overloaded\n";
	// }
};
int main(){
	B b;
	b.fun();
	b.A::fun(1);
	return 0;
}