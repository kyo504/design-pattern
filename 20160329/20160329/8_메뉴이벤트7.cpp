// 8_�޴��̺�Ʈ7
#include <iostream>
using namespace std;

class Dialog
{
public:
	void close() { cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

#include <functional>
// �̹� ǥ�ؿ� ������ �Լ� �����Ͱ� �ֽ��ϴ�.
// TR1 - 2008�⵵�� �߰��Ǿ����ϴ�.

void goo(int n)							{ printf("goo: %d\n", n); }
void hoo(int a, int b)					{ printf("hoo %d %d\n", a, b); }
void koo(int a, int b, int c, int d)	{ printf("koo: %d, %d, %d, %d\n", a, b, c, d); }

using namespace std::placeholders;

int main()
{
	function<void(int)> f = &goo;
	f(10);

	f = bind(&hoo, 10, _1);
	f(300);

//	f = bind(&koo, 10, _1, 30, _1);
//	f(20);
}

#if 0
int main()
{
	function<void()> f = &foo;
	f();

	f = bind(&goo, 10);
	f = bind(&hoo, 10, 20);
	f = bind(&koo, 10, 20, 30, 40);
	f();
}
#endif

#if 0
int main()
{
	function<void()> f = &foo;
	f();

	Dialog dialog;
	f = bind(&Dialog::close, &dialog);
	f();
}
#endif