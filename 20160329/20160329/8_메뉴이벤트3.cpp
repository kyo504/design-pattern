// 8_�޴��̺�Ʈ3
#include <iostream>
#include <vector>
using namespace std;

struct IMenuListener
{
  virtual void onCommand(int id) = 0;
  virtual ~IMenuListener() {}
};

class MenuItem
{
  int id;
  vector<IMenuListener*> v;
public:
  MenuItem(int i) : id(i) {}
  void addListener(IMenuListener* p)
  {
    v.push_back(p);
  }

  virtual void command()
  {
    // �޴��� ���õ� ����� �ٽ� �ܺο� �˷��� �Ѵ�.
    // "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�." ��� ǥ��
    // => ��ϵ� ��� ��ü���� �˷��ش�. -> ������ ����
    for (int i = 0; i < v.size(); ++i)
      v[i]->onCommand(id);
  }
};

class Window : public IMenuListener
{
public:
  virtual void onCommand(int id)
  { cout << "Window onCommand" << endl; }
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
  }

  void open() { cout << "Dialog open" << endl; }
  void close() { cout << "Dialog close" << endl; }
};

int main()
{
  Dialog dialog;
  Window window;

  MenuItem m1(11);
  m1.addListener(&dialog);
  m1.addListener(&window);

  m1.command();
}
