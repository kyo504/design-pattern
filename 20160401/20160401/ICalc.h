// ICalc.h
#include "ioacademy.h"
using namespace std;

struct ICalc
{
	virtual int add(int a, int b) = 0;
	virtual int sub(int a, int b) = 0;

	virtual ~ICalc() {}
};

// ��ü�� �����ϴ� ����� ���� �����ڰ� �������־�� �Ѵ�.
// asInterface, CoCreateInstance

static ICalc* CreateInstance()
{
	// 1. CalcProxy.dll�� �ε��մϴ�.
	void* addr = IoLoadModule("CalcProxy.dll");

	// 2. Calc ��ü �����ϴ� �Լ��� ã�ƾ� �մϴ�.
	typedef ICalc*(*F)();
	F f = (F)IoGetFunctionAddress(addr, "CreateCalc");

	// 3. Calc ��ü ����
	ICalc* pCalc = f();

	// ������ ������ ���縦 �𸣰� ����� ������ �� �ֽ��ϴ�.
	cout << pCalc->add(10, 20) << endl;
	cout << pCalc->sub(10, 20) << endl;
}