// 1_�޼�����
// MFC, wxWidget
// : ���� �Լ� ���̺��� ������带 ���̱� ���� ����ڰ� ���� ���̺��� �����ϵ���
//   ����� ����Դϴ�.

#include "ioacademy.h"
using namespace ioacademy;

#include <map>
#include <iostream>
using namespace std;

class Window;
struct AFX_MSG
{
  int message;                // �޼��� ��ȣ
  void(Window::*handler)();   // ó���� �Լ��� �ּ�
};

class Window
{
  static map<int, Window*> this_map;
public:

  // ���� ��� �ڽ� Ŭ������ �ڽ��� ó���ϰ��� �ϴ� �̺�Ʈ��
  // �̺�Ʈ �ڵ鷯�� ���� �迭�� �����ؾ� �Ѵ�.
  virtual AFX_MSG* GetMessageMap() { return 0; }

  void create()
  {
    int handle = IoMakeWindow(foo);
    this_map[handle] = this;
  }

  // �̹� ������ �ٽ��� �Ʒ� �Լ��Դϴ�.
  static int foo(int handle, int msg, int param1, int param2)
  {
    Window* self = this_map[handle];
    if (self == 0) return 0;

    // 1. �迭�� ���´�.
    AFX_MSG* msgArray = self->GetMessageMap();
    if (msgArray == 0)  // ó���� �޼����� ���� ���
      return 0;

    // 2. �迭�� ���� �޼����� �ִ��� ���θ� Ȯ���ϰ�
    //    ��ϵ� �ڵ鷯�� ȣ���Ѵ�.
    for (;msgArray->message != 0; msgArray++)
    {
      if (msgArray->message == msg) 
      {
        void (Window::*f)() = msgArray->handler;
        (self->*f)();
      }
    }

    return 0;
  }


};

map<int, Window*> Window::this_map;

class MyWindow : public Window
{
public:
  void onLButtonDown() {
    cout << "LButton" << endl;
  }

  void onKeyDown() {
	  cout << "KeyDown" << endl;
  }
  
  void foo() { cout << "foo" << endl; }


  virtual AFX_MSG* GetMessageMap() {
    typedef void(Window::*HANDLER)();

    static AFX_MSG msgMap[] = {
      { WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::onLButtonDown) },
	  { WM_KEYDOWN, static_cast<HANDLER>(&MyWindow::onKeyDown) },
      { 0, 0 }
    };

    return msgMap;
  }
};


int main()
{
  MyWindow w;
  w.create();       // �� ���� �����찡 ��������� �մϴ�.
                    // ���� ��ư�� ������ "LBUTTON" �̶�� ��µǾ�� �մϴ�.
  IoProcessMessage();
}