// 8_�޴��̺�Ʈ2
#include <iostream>
using namespace std;
// 1. �������̽� ����� ������ ����: Java, Android

// �޴��� ó���ϰ� ���� ��� Ŭ������ �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct IMenuListener
{
  virtual void onCommand(int id) = 0;
  virtual ~IMenuListener() {}
};

class MenuItem
{
  int id;
  IMenuListener* pListener;
public:
  MenuItem(int i) : id(i), pListener(0) {}
  void setListener(IMenuListener* p) { pListener = p; }
  //   addListener

  virtual void command()
  {
    // �޴��� ���õ� ����� �ٽ� �ܺο� �˷��� �Ѵ�.
    // "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�." ��� ǥ��
    if (pListener)
      pListener->onCommand(id);
  }
};

class Dialog : public IMenuListener
{
public:
  virtual void onCommand(int id)
  {
    // � ��ü�κ��� �̺�Ʈ�� �߻��ߴ��� ���θ� �ݵ�� �б��ϴ� �ڵ尡
    // �ʿ��ϴ�.
    switch (id)
    {
    case 11: open(); break;
    case 12: close(); break;
    }

    close();
  }

  void open() { cout << "Dialog open" << endl; }
  void close() { cout << "Dialog close" << endl; }
};

int main()
{
  Dialog dialog;

  MenuItem m1(11); MenuItem m2(12);
  m1.setListener(&dialog);
  m2.setListener(&dialog);

  m1.command();
}
