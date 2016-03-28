// 7_가상소멸자.cpp
#include <iostream>
using namespace std;

// Inside C++ Object - 스탠리 립만

// 1. 부모 클래스의 소멸자가 가상 함수이면, 모든 자식의 소멸자도 가상 함수이다.
// 2. 모든 부모 클래스의 소멸자는 반드시 가상 함수이어야 한다.
//		가상 함수 소멸자를 제공하고 있지 않다면 자식이 온전하게 소멸되지 않을 수 있으며 이는 메모리 누수로 이어질 수도 있다.

class Base
{
public:
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived() { cout << "자원 할당" << endl; }
	~Derived() { cout << "자원 해제" << endl; }
};

int main()
{
	Base* p = new Derived;
	delete p;

	//Derived d;
}