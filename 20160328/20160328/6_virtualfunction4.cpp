// 6_�����Լ��ǿ���4.cpp

#include <iostream>
using namespace std;

// ����Ʈ ����: ������ �ð��� �����ȴ�.
// ���� �Լ�: ���� �ð��� �����ȴ�.
// �׷��� ������ ���� ��� ���� �ʴ°� ����

// 1. ���� �Լ������� �ǵ����̸� ����Ʈ ���ڸ� ������� ����. �ֳ��ϸ� ����� ���� �����ϱ� ��ƴ�.
// 2. ������ ����ߴٸ� �������� �� ���� ����Ʈ ���ڸ� �������� ����. 

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