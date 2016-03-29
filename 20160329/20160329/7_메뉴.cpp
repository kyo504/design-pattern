// 7_�޴�
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>  // getch();
using namespace std;

// Composite Pattern
// : ���� ��ü�� �����ϴ� ���

// 1. ���� ��ü(PopupMenu)�� ���� ��ü(MenuItem)�� ���հ�ü�� ��� ������ �� �ִ�
//   => ���� ��ü�� ���� ��ü���� ������ �θ� �����Ѵ�.

// 2. ���� ��ü�� ���� ��ü�� ���Ͻ� �ȴ�. (������ ����, ��� command()�� �ִ�)
//   => command() �ݵ�� �θ� Ŭ�����κ��� �����Ǿ�� �Ѵ�. - ������


// ��� �޴��� ������ �θ�
class BaseMenu
{
  string title;
public:
  BaseMenu(string s) : title(s) {}
  virtual ~BaseMenu() {}

  string getTitle() { return title; }

  virtual void command() = 0;
  // �ݵ�� command()�� �θ��� BaseMenu�κ��� �;� �Ѵ�.
  // �θ� ���忡���� �������� ������ ����, �ڽ��� �ݵ�� ������ �Ѵٸ�
  // ���� �����Լ��� ����.
};

class MenuItem : public BaseMenu
{
public:
  MenuItem(string s) : BaseMenu(s) {}

  void command()
  {
    cout << getTitle() << " �޴��� ���õǾ���." << endl;
    getch();
  }
};

#define clrscr() system("cls")      // system("clear")

// �Ʒ� Ŭ������ �ٽ��Դϴ�.
class PopupMenu : public BaseMenu
{
  vector<BaseMenu*> v;  // ����� �ռ�
public:
  PopupMenu(string s) : BaseMenu(s) {}

  void addMenu(BaseMenu* p) { v.push_back(p); }

  void command()
  {
    while (1)
    {
      clrscr();

      int sz = v.size();
      for (int i = 0; i < sz; i++)
        cout << i + 1 << ". " << v[i]->getTitle() << endl;
      cout << sz + 1 << ". ���� �޴���" << endl;

      cout << "�޴��� �����ϼ���. >> ";
      int cmd;
      cin >> cmd;

      if (cmd == sz + 1)
        break;

      if (cmd < 1 || cmd > sz + 1)  // �߸��� �Է�
        continue;

      // ���õ� �޴��� �����Ѵ�.
      v[cmd - 1]->command();
    }
  }
};

int main()
{
  PopupMenu* menubar = new PopupMenu("MENUBAR");
  PopupMenu* p1 = new PopupMenu("ȭ�� ����");
  PopupMenu* p2 = new PopupMenu("�Ҹ� ����");

  menubar->addMenu(p1);
  p1->addMenu(p2);

  p1->addMenu(new MenuItem("�ػ� ����"));
  p1->addMenu(new MenuItem("���� ����"));
  p1->addMenu(new MenuItem("��Ÿ ����"));

  p2->addMenu(new MenuItem("���� ����"));
  p2->addMenu(new MenuItem("���� ����"));

  menubar->command();
}