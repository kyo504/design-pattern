// 2_thiscall4.cpp
// 멀티 스레드를 캡슐화 해 봅시다.

#include <Windows.h>

#include <iostream>
using namespace std;

class Thread
{
public:
	void run() {
		CreateThread(0, 0, _threadloop, this, 0, 0);
	};

	// 1. 아래 함수가 static 멤버 함수 일수 밖에 없는 이유를 정확히 알아야 한다.
	// 2. 정적 멤버 함수에는 this가 없으므로 함수 인자로 this를 전달하는 기술이 필요하다.
	static DWORD __stdcall _threadloop(void* user)
	{
		Thread* self = static_cast<Thread*>(user);

		self->threadLoop();		// threadLoop(self); 이렇게 되겠징...
		return 0;
	};

	virtual bool threadLoop() { return false; }
};

class MyThread : public Thread
{
public:
	virtual bool threadLoop()
	{
		cout << "MyThread threadLoop()" << endl;
		return true;
	}
};

int main()
{
	MyThread t;
	t.run();

	getchar();
}


#if 0
DWORD __stdcall foo(void* p)
{
	cout << "Thread start!!" << endl;
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, "A", 0, 0);
	getchar();
}
#endif

