// 6_가상함수의원리3.cpp

#include <iostream>
using namespace std;

// 일반 함수일 때와 가상 함수일 때 결과가 다르다!
// 일반 함수일 때 : goo가 호출 됨
// 가상 함수일 때 : foo가 호출 됨
// Why?

class A
{
	int a;
public:
	//void foo() { cout << "A foo" << endl; }
	virtual void foo() { cout << "A foo" << endl; }
};

class B
{
	int b;
public:
	//void goo() { cout << "B goo" << endl; }
	virtual void goo() { cout << "B goo" << endl; }
};

int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);
	p->goo();

	return 0;
}

