// 7_����Ҹ���.cpp
#include <iostream>
using namespace std;

// Inside C++ Object - ���ĸ� ����

// 1. �θ� Ŭ������ �Ҹ��ڰ� ���� �Լ��̸�, ��� �ڽ��� �Ҹ��ڵ� ���� �Լ��̴�.
// 2. ��� �θ� Ŭ������ �Ҹ��ڴ� �ݵ�� ���� �Լ��̾�� �Ѵ�.
//		���� �Լ� �Ҹ��ڸ� �����ϰ� ���� �ʴٸ� �ڽ��� �����ϰ� �Ҹ���� ���� �� ������ �̴� �޸� ������ �̾��� ���� �ִ�.

class Base
{
public:
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived() { cout << "�ڿ� �Ҵ�" << endl; }
	~Derived() { cout << "�ڿ� ����" << endl; }
};

int main()
{
	Base* p = new Derived;
	delete p;

	//Derived d;
}