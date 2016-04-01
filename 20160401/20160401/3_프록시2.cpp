// ���Ͻ�
// Remote Proxy - IPC
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// ���� ��ſ� ����� Ŭ������ ����� ���ô�.
class Calc
{
  int handle;
public:
  Calc() { handle = IoFindServer("CalcServer"); }

  int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
  int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};
// ���� �����ڰ� �� Ŭ������ �����ؼ� Ŭ���̾�Ʈ �����ڿ��� 
// �����ϴ� �� �Դϴ�.

// ���� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// 1. ICalc.h: �������̽� ���
// 2. CalcProxy.dll: Proxy Class�� �ִ� DLL


int main()
{
  Calc* pCalc = new Calc;
  cout << pCalc->add(1, 2) << endl;
  cout << pCalc->sub(1, 2) << endl;
}