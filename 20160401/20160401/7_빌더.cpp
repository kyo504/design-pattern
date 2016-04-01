#include <iostream>
#include <string>
using namespace std;

struct IBuilder
{
  virtual void makeHat() = 0;
  virtual void makeUniform() = 0;
  virtual void makeShoes() = 0;

  virtual string getResult() = 0;

  virtual ~IBuilder() {}
};

class Director
{
  IBuilder* pBuilder;
public:
  void setBuilder(IBuilder* p) { pBuilder = p; }

  // �Ʒ� �Լ��� ĳ���͸� ���� �����ϴ� �Լ��Դϴ�.
  string construct()
  {
    pBuilder->makeHat();
    pBuilder->makeUniform();
    pBuilder->makeShoes();

    return pBuilder->getResult();
  }
};

// �پ��� ������ ������ �����մϴ�.
class Korean : public IBuilder
{
  string c;
public:
  virtual void makeHat() {
    c += "��";
  }
  virtual void makeUniform() {
    c += "�Ѻ�";
  }

  virtual void makeShoes() {
    c += "����";
  }
  
  virtual string getResult() { return c; }
};

class American : public IBuilder
{
public:
  string c;
public:
  virtual void makeHat() {
    c += "�߱�����";
  }
  virtual void makeUniform() {
    c += "�纹";
  }

  virtual void makeShoes() {
    c += "����";
  }

  virtual string getResult() { return c; }
};

int main()
{
  Korean korean; American american;
  Director director;

  // ĳ���� ���� ȭ��ǥ Ű�� ������ �� �ڵ带 �����Ѵ�.
  director.setBuilder(&korean);
  cout << director.construct() << endl;

  director.setBuilder(&american);
  cout << director.construct() << endl;
}