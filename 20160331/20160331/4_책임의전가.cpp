// 4_å��������
#include "ioacademy.h"
using namespace ioacademy;

#include <map>
#include <iostream>
using namespace std;

class Window
{
  static map<int, Window*> this_map;
public:
  void create()
  {
    int handle = IoMakeWindow(foo);
    this_map[handle] = this;
  }

  virtual void onLButtonDown() {}
  virtual void onKeyDown() {}

  // http://d.pr/n/19DtC
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
    }

    return 0;
  }


};

map<int, Window*> Window::this_map;

// http://d.pr/n/mDpc
class MyWindow : public Window
{
public:
  virtual void onLButtonDown() {
    cout << "LButton" << endl;
  }

  virtual void onKeyDown() {
    cout << "Key Down" << endl;
  }
};


int main()
{
  MyWindow w;
  w.create();       // �� ���� �����찡 ��������� �մϴ�.
                    // ���� ��ư�� ������ "LBUTTON" �̶�� ��µǾ�� �մϴ�.
  IoProcessMessage();
}




#if 0
// http://d.pr/n/1j6Hs
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
  }

  return 0;
}

int main()
{
  int h1 = IoMakeWindow(foo);

  IoProcessMessage();
}
#endif






