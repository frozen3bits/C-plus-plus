#include<iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"A"<<endl;
	}
	~A(){
		cout<<"A"<<endl;
	}
};
class B{
public:
	B(){
		cout<<"B"<<endl;
	}
	~B(){
		cout<<"B"<<endl;
	}
};
class C{
public:
	C(){
		cout<<"C"<<endl;
	}
	~C(){
		cout<<"C"<<endl;
	}
};
class D{
public:
	D(){
		cout<<"D"<<endl;
	}
	~D(){
		cout<<"D"<<endl;
	}
};
class M : public A, virtual public B, public C, virtual public D{
public:
	M():A(),B(),C(),D(){} 
};
int main(){
	M m;
}
