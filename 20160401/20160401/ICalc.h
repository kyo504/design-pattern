// ICalc.h
#include "ioacademy.h"
using namespace std;

struct ICalc
{
	virtual int add(int a, int b) = 0;
	virtual int sub(int a, int b) = 0;

	virtual ~ICalc() {}
};

// 객체를 생성하는 방법도 서버 개발자가 제공해주어야 한다.
// asInterface, CoCreateInstance

static ICalc* CreateInstance()
{
	// 1. CalcProxy.dll을 로드합니다.
	void* addr = IoLoadModule("CalcProxy.dll");

	// 2. Calc 객체 생성하는 함수를 찾아야 합니다.
	typedef ICalc*(*F)();
	F f = (F)IoGetFunctionAddress(addr, "CreateCalc");

	// 3. Calc 객체 생성
	ICalc* pCalc = f();

	// 이제는 서버의 존재를 모르고도 기능을 수행할 수 있습니다.
	cout << pCalc->add(10, 20) << endl;
	cout << pCalc->sub(10, 20) << endl;
}