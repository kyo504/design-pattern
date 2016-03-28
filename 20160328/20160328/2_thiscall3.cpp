// 2_thiscall3.cpp
#include <iostream>
using namespace std;

// 멤버 함수와 함수 포인터 이야기

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

// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다. (this가 필요하기 때문이다)
// 2. 멤버 함수 포인터를 만들고 사용하는 방법
// 3. 일반 함수 포인터에 정적 멤버 함수의 주소를 담을 수 있다. (this가 없기 때문이다)

int main()
{
	void(*f3)() = &Dialog::goo;
	f3();

	Dialog dlg;

	void(Dialog::*f2)() = &Dialog::close;
	//f2(); // 객체가 생성되어 있지 않다면 호출 불가임( compile error)
	//dlg.f2();	// 실제 멤버 함수가 아니기 때문에 호출 불가임
	(dlg.*f2)();	// 실제 멤버 함수가 아니기 때문에 호출 불가임


	//void(*f1)() = &Dialog::close;


	void(*f)() = &foo;
	f();

	return 0;
}