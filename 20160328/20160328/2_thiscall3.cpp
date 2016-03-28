// 2_thiscall3.cpp
#include <iostream>
using namespace std;

// ��� �Լ��� �Լ� ������ �̾߱�

class Dialog
{
public:
	void close() {
		cout << "Dialog close" << endl; 
	};

	static void goo()
	{
		cout << "goo" << endl;
	}
};

void foo() { cout << "foo" << endl; }

// 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����. (this�� �ʿ��ϱ� �����̴�)
// 2. ��� �Լ� �����͸� ����� ����ϴ� ���
// 3. �Ϲ� �Լ� �����Ϳ� ���� ��� �Լ��� �ּҸ� ���� �� �ִ�. (this�� ���� �����̴�)

int main()
{
	void(*f3)() = &Dialog::goo;
	f3();

	Dialog dlg;

	void(Dialog::*f2)() = &Dialog::close;
	//f2(); // ��ü�� �����Ǿ� ���� �ʴٸ� ȣ�� �Ұ���( compile error)
	//dlg.f2();	// ���� ��� �Լ��� �ƴϱ� ������ ȣ�� �Ұ���
	(dlg.*f2)();	// ���� ��� �Լ��� �ƴϱ� ������ ȣ�� �Ұ���


	//void(*f1)() = &Dialog::close;


	void(*f)() = &foo;
	f();

	return 0;
}