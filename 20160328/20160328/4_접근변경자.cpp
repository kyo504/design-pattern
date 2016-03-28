// 4_접근변경자.cpp

#include <iostream>
using namespace std;

class Base
{
private:
	int a;
protected:
	int b;
public:
	int c;
};

// 1. 부모 클래스의 private 접근은 영향을 받지 않는다.
// 2. protected 상속
//		1) protected -> protected
//		2) prote	//: <접근 변경자>> Base
// 3 private 상속
//		1) protected -> private
//		2) protected -> private
class Derived : public Base
{

};

int main()
{
	Base b; b.c = 10;
	Derived d; b.c = 10;
}