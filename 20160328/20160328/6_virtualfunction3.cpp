// 6_�����Լ��ǿ���3.cpp

#include <iostream>
using namespace std;

// �Ϲ� �Լ��� ���� ���� �Լ��� �� ����� �ٸ���!
// �Ϲ� �Լ��� �� : goo�� ȣ�� ��
// ���� �Լ��� �� : foo�� ȣ�� ��
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

