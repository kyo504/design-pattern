// 6_Application Framework
#include <iostream>
using namespace std;

// 여기부터는 라이브러리 내부 코드입니다. dll로 숨겨져 있습니다.
class CWinApp;
CWinApp* g_app;
class CWinApp
{
public:
	CWinApp() { g_app = this; }
	virtual bool InitInstance() { return false; }
	virtual int ExitInstance() { return 0; }
	virtual int Run() { return 0; }
};

CWinApp* AfxGetApp() { return g_app; }

int main()
{
	CWinApp* pApp = AfxGetApp();

	if (pApp->InitInstance())
		pApp->Run();

	pApp->ExitInstance();
}

//-----------------------------------------
// 여기부터는 라이브러리 사용자 코드
// 규칙 1. CWinApp의 파생 클래스를 만들어야 한다.
// 규칙 2. InitInstance() 가상함수를 재정의해서 초기화 작업을 수행한다.
// 규칙 3. 사용자가 만든 클래스를 전역으로 반드시 한개 생성해야 한다.

// 미리 정의된 흐름 - "template method" 패턴이 적용되는 경우가 많다.
//                  => 전체적은 흐름을 라이브러리 안에 각 단계를 가상함수화해서 자식이 재정의 할 수 있도록...

// QT - C++
// GTK - C (Object oriented C)

class CMyApp : public CWinApp
{
public:
	virtual bool InitInstance()
	{
		cout << "프로그램 시작" << endl;
		return false;
	}

	virtual int ExitInstance()
	{
		cout << "프로그램 종료" << endl;
		return 0;
	}
};

CMyApp thsApp;