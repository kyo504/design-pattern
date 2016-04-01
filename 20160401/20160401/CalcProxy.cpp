// CalcProxy.cpp
#include "ICalc.h"
#include "ioacademy.h"
using namespace ioacademy;

class Calc : public ICalc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};
// ���� �����ڰ� �� Ŭ������ �����ؼ� Ŭ���̾�Ʈ �����ڿ��� �����ϴ� ���Դϴ�.


// DLL ���ʿ��� Proxy�� ����� �Լ��� ���� �����ؾ� �մϴ�.
extern "C" __declspec(dllexport) ICalc* CreateCalc()
{
	return new Calc;
}

// ������ ��� ������Ʈ
// cl CalcProxy.cpp /LD / link user32.lib gdi32.lib kernel32.lib