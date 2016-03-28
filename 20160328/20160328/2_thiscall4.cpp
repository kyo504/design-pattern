// 2_thiscall4.cpp
// ��Ƽ �����带 ĸ��ȭ �� ���ô�.

#include <Windows.h>

#include <iostream>
using namespace std;

class Thread
{
public:
	void run() {
		CreateThread(0, 0, _threadloop, this, 0, 0);
	};

	// 1. �Ʒ� �Լ��� static ��� �Լ� �ϼ� �ۿ� ���� ������ ��Ȯ�� �˾ƾ� �Ѵ�.
	// 2. ���� ��� �Լ����� this�� �����Ƿ� �Լ� ���ڷ� this�� �����ϴ� ����� �ʿ��ϴ�.
	static DWORD __stdcall _threadloop(void* user)
	{
		Thread* self = static_cast<Thread*>(user);

		self->threadLoop();		// threadLoop(self); �̷��� �ǰ�¡...
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

