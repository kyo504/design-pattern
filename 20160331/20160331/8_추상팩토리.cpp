#include <iostream>
using namespace std;
// 8_�߻����丮
// abstract factory pattern

// �ǵ�: ���嵵 �������̽� ������� �����ؼ�
//       ��ü�����ϰ� ����.

// Qt���� �����ϴ� GUI Look & Feel�� ������ ���캾�ô�.


struct IButton {};
class XPButton : public IButton {};
class GTKButton : public IButton {};

struct IEdit {};
class XPEdit : public IEdit {};
class GTKEdit : public IEdit {};

struct IFactory
{
  virtual IButton* createButton = 0;
  virtual IEdit*   createEdit() = 0;

  virtual ~IFactory() {}
};

// ��Ÿ�Ͽ� ���� ��Ʈ���� ����� ������ ��������.
class XPFactory : public IFactory
{
public:
  IButton* createButton() { return new XPButton; }
  IEdit*   createEdit()   { return new XPEdit; }
  //....
};

class GTKFactory : public IFactory
{
public:
  IButton* createButton() { return new GTKButton; }
  IEdit*   createEdit()   { return new GTKEdit; }
  //....
};

int main(int argc, char* argv[])
{
  IFactory* factory;
  if (strcmp(argv[1], "--style=GTK")) {
    factory = new GTKFactory;
  }
  else {
    factory = new XPFactory;
  }
}

#if 0
// a.exe --style=XP
int main(int argc, char* argv[])
{
  IButton* p1;
  IEdit* p2;
  if (strcmp(argv[1], "--style=GTK")) {
    p1 = new GTKButton;
    p2 = new GTKEdit;
    //...
  }
  else {
    p1 = new XPButton;
    p2 = new XPEdit;
    //...
  }

  // �����츦 �׸��� �ڵ忡��
  // p->draw();
}
#endif