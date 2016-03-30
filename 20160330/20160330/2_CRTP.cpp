// 2_CRTP
#include <iostream>
using namespace std;

class MyWindow;


//       Mixin template
// CRTP: Curiosly Recurring Template Pattern - C++ idioms
// : �θ� Ŭ������ ���ø� �ε� �ڽĿ��� ���ø��� ���ڷ� �ڽ��� Ÿ���� �����ϴ� ���

// �������� Ȱ���� �����ѵ�, �Ʒ� �ڵ�� �񰡻��Լ��� �����Լ�ó�� 
// �����ϰ� ����� ���.

// MS ���̺귯�� �� WTL, ATL�� �Ʒ��� ���� ���谡 �Ǿ� �ֽ��ϴ�.
template <typename T>
class Window
{
public:
  void msgLoop()
  {
    // this : Window* 
    (static_cast<T*>(this))->onClick();

  }

  void onClick() {}
};

class MyWindow : public Window<MyWindow>
{
public:
  void onClick() { cout << "My Window on Click" << endl; }
};

int main()
{
  MyWindow w;
  w.msgLoop();
}








