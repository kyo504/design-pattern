// 4_å��������
#include "ioacademy.h"
using namespace ioacademy;

// å���� ���� ����
// - �̺�Ʈ �߻��� ó������ ���� ��� ���� ��ü���� �����Ѵ�.
// - ó���� �� ���� ������ ���� ���� �̺�Ʈ�� �����Ѵ�.

// ��� 
// 1) ��Ų��� �迭 - ���ھ�, ���ھ� ��ġ: �������� ü��
//  : View -> ViewController -> AppDelegate

// 2) MFC���� �޴� �޼��� - å���� ��
//  : View -> Document -> Frame -> App

#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Window
{
  static map<int, Window*> this_map;

  int handle;                // C �Լ��� ���� �����츦 ������ �����ϱ� ���ؼ���
                             // �ݵ�� �����ؾ� �Ѵ�.

  Window* parent;            // �θ� ������� 1���̴�.
  vector<Window*> children;  // �ڽ��� �������̴�.
public:
  Window() : parent(0) {}

  void addChild(Window* p)
  {
    p->parent = this;
    children.push_back(p);

    // C �Լ��� �ڽ� �����츦 ���δ�.
    IoAddChild(this->handle, p->handle);
  }

  void create()
  {
    handle = IoMakeWindow(foo);
    this_map[handle] = this;
  }

  virtual void onLButtonDown() {}
  virtual void onKeyDown() {}

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

class MyWindow : public Window
{
public:
  virtual void onLButtonDown() {
    cout << "LButton" << endl;
  }
};

class ImageView : public Window
{
public:
  virtual void onLButtonDown() {
    cout << "Image" << endl;
  }
};

int main()
{
  MyWindow w;
  w.create();

  ImageView imageView;
  imageView.create();

  w.addChild(&imageView);

  IoProcessMessage();
}
