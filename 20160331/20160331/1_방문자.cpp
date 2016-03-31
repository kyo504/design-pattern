// 1_�湮��
// �����̳�(���� ��ü)�� �ۿ��ϴ� ���� 2����
// �ݺ���: �����̳ʳ� ���� ��ü�� ���� ������ ������� ��Ҹ� ����
// �湮��: �����̳ʿ� ���� ��ü�� ���� ������ ������� ��ҿ� ����

// ���� ��ü�� �����ϴ� ��� - menu, folder: Composite Pattern
// - �湮�� ������ Composite ���ϰ� ����Ǿ ���� ���˴ϴ�.
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>  // getch();
using namespace std;

// �޴� �ý��ۿ� ����Ǵ� �湮���� �������̽�
class PopupMenu;
class MenuItem;
struct IMenuVisitor
{
  virtual void visit(PopupMenu* p) = 0;
  virtual void visit(MenuItem* p) = 0;
  virtual ~IMenuVisitor() {}
};

struct IMenuAcceptor
{
  virtual void accept(IMenuVisitor* visitor) = 0;
  virtual ~IMenuAcceptor() {}
};

class BaseMenu : public IMenuAcceptor
{
  string title;
public:
  BaseMenu(string s) : title(s) {}
  virtual ~BaseMenu() {}

  string getTitle() { return title; }
  //---------
  void setTitle(const string& s) { title = s; }
  //---------

  virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
public:
  MenuItem(string s) : BaseMenu(s) {}

  virtual void accept(IMenuVisitor* visitor)
  {
    visitor->visit(this);   // �ڽ��� �����Ѵ�.
  }

  void command()
  {
    cout << getTitle() << " �޴��� ���õǾ���." << endl;
    getch();
  }
};

#define clrscr() system("cls")      // system("clear")

class PopupMenu : public BaseMenu
{
  vector<BaseMenu*> v;  // ����� �ռ�
public:

  virtual void accept(IMenuVisitor* visitor)
  {
    visitor->visit(this);

    // ���� �����ϰ� �ִ� ��� �޴��鿡 ���ؼ��� �湮�ڸ� �����ؾ� �Ѵ�. - �ٽ�!!!
    for (BaseMenu* e : v) // Range-for
      e->accept(visitor);
  }
  
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

//--------------------------------------
// �޴� �ý��ۿ� �پ��� ����� �߰��ϴ� �湮�ڵ��� �����ϸ� �˴ϴ�.
class TitleDecorationVisitor : public IMenuVisitor
{
public:
  virtual void visit(MenuItem* p) {}
  virtual void visit(PopupMenu* p) 
  {
    string s = p->getTitle();
    s = s + "  >";
    p->setTitle(s);  // ĸ��ȭ ���� ����
                     // ������ �����ߴ� ��å�� �ٲ�� �Ѵ�.
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

  TitleDecorationVisitor v;
  menubar->accept(&v);
  menubar->command();
}