// 2_thiscall6

#include "ioacademy.h"
using namespace ioacademy;

#include <iostream>
#include <map>
using namespace std;

class Window
{
	static map<int, Window*> this_map;

public:

	void create() {
		int id = IoMakeWindow(foo);
		this_map[id] = this;
	};

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->onLButtonDown();
			break;
		case WM_KEYDOWN:
			self->onKeyDown();
			break;
		default:
			break;
		}

		return 0;
	};

	virtual void onLButtonDown() = 0;
	virtual void onKeyDown() = 0;
};

map<int, Window*> Window::this_map;

class MyWindow : public Window
{
public:
	virtual void onLButtonDown() {
		cout << "LButton" << endl;
	};
	virtual void onKeyDown() {
		cout << "KeyDown" << endl;
	};
};

int main()
{
	MyWindow w;
	w.create();

	IoProcessMessage();

	return 0;
}

#if 0
int foo(int handle, int msg, int param1, int param2)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		cout << "left button down" << endl;
		break;
	case WM_KEYDOWN:
		cout << "key down" << endl;
		break;
	default:
		break;
	}

	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);
	int h2 = IoMakeWindow(foo);

	IoProcessMessage();
}
#endif