// 4_���ٺ�����.cpp

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

// 1. �θ� Ŭ������ private ������ ������ ���� �ʴ´�.
// 2. protected ���
//		1) protected -> protected
//		2) prote	//: <���� ������>> Base
// 3 private ���
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