// 6_Application Framework
#include <iostream>
using namespace std;

// ������ʹ� ���̺귯�� ���� �ڵ��Դϴ�. dll�� ������ �ֽ��ϴ�.
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
// ������ʹ� ���̺귯�� ����� �ڵ�
// ��Ģ 1. CWinApp�� �Ļ� Ŭ������ ������ �Ѵ�.
// ��Ģ 2. InitInstance() �����Լ��� �������ؼ� �ʱ�ȭ �۾��� �����Ѵ�.
// ��Ģ 3. ����ڰ� ���� Ŭ������ �������� �ݵ�� �Ѱ� �����ؾ� �Ѵ�.

// �̸� ���ǵ� �帧 - "template method" ������ ����Ǵ� ��찡 ����.
//                  => ��ü���� �帧�� ���̺귯�� �ȿ� �� �ܰ踦 �����Լ�ȭ�ؼ� �ڽ��� ������ �� �� �ֵ���...

// QT - C++
// GTK - C (Object oriented C)

class CMyApp : public CWinApp
{
public:
	virtual bool InitInstance()
	{
		cout << "���α׷� ����" << endl;
		return false;
	}

	virtual int ExitInstance()
	{
		cout << "���α׷� ����" << endl;
		return 0;
	}
};

CMyApp thsApp;