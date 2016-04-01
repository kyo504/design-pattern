// ���Ͻ�
// Remote Proxy - IPC
#include <iostream>
#include "ioacademy.h"

using namespace std;
using namespace ioacademy;

// Proxy Pattern
// Remote Proxy: IPC, Network ���� ��Ȱ�� ����ϴ� Ŭ����
// Smart Proxy: ���� ��ҿ� �߰����� �۾��� �ϴ� Ŭ����

int main()
{
  // 1. ������ ��ȣ�� ���´�.
  int handle = IoFindServer("CalcServer");
  cout << "���� ��ȣ: " << handle << endl;

  cout << IoSendServer(handle, 1, 1, 2) << endl;
  cout << IoSendServer(handle, 2, 1, 2) << endl;
}