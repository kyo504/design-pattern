// 6_가상함수의원리4.cpp

#include <iostream>
using namespace std;

// 디폴트 인자: 컴파일 시간에 결정된다.
// 가상 함수: 실행 시간에 결정된다.
// 그렇기 때문에 둘을 섞어서 쓰지 않는게 좋다

// 1. 가상 함수에서는 되도록이면 디폴트 인자를 사용하지 말자. 왜냐하면 결과를 쉽게 예측하기 어렵다.
// 2. 누군가 사용했다면 재정의할 때 절대 디폴트 인자를 변경하지 말자. 

class A
{
public:
	virtual void foo(int a=10)
	{
		cout << "A: " << a << endl;
	}
};

class B : public A
{
public:
	virtual void foo(int a = 20)
	{
		cout << "B: " << a << endl;
	}
};

int main()
{
	A* p = new B;
	p->foo();
}