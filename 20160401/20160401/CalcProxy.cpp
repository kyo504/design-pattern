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
// 서버 제작자가 위 클래스를 제작해서 클라이언트 개발자에게 배포하는 것입니다.


// DLL 안쪽에서 Proxy를 만드는 함수를 같이 제공해야 합니다.
extern "C" __declspec(dllexport) ICalc* CreateCalc()
{
	return new Calc;
}

// 개발자 명령 프롬프트
// cl CalcProxy.cpp /LD / link user32.lib gdi32.lib kernel32.lib