// 4_���ڷ����� ����
#include <iostream>
using namespace std;

// ����� �ռ� ����� ����� ������ ���� 2����
// 1. ������Ʈ: ����� �ռ��� ���� ���� ��ü�� ����
// 2. ���ڷ�����: ����� �ռ��� ���� ����� �߰�

// �ٽ� 2����
// 1. ������ ���� ����� �߰� - ������ ����� �߰�
// 2. ����� �ռ� - ����� �߰��ߴ� ��ü�� �ٽ� �߰��� �� �ִ�.

class Item
{
public:
  virtual void print() = 0;
  virtual ~Item() {}
};

class Ticket : public Item
{
public:
  void print()
  {
    cout << "���� ����ȸ - 2016.12.25" << endl;
  }
};

// ��� ����(������)�� ������ Ư¡�� �θ�� ��������
class Decorator : public Item
{
  Item& item;
public:
  Decorator(Item& i) : item(i) {}
  void print() { item.print(); }
};

class Ad1 : public Decorator
{
public:
  Ad1(Item& t) : Decorator(t) {}

  void print()
  {
    Decorator::print();
    cout << "�ڵ��� ����" << endl;
  }
};

class Ad2 : public Decorator
{
public:
  Ad2(Item& t) : Decorator(t) {}

  void print()
  {
    cout << "TV ����" << endl;
    Decorator::print();
  }

};

int main()
{
  Ticket t;

  // ����� �߰��� ��ü�� �ٽ� ����� �߰��ϰ� �ʹ�.
  Ad1 ad1(t);
  Ad2 ad2(ad1);

  ad2.print();
}


//---------------------------
// Zip���� ����Ǿ� �ִ� ������ �о�� �Ѵ�. - NIO(New IO)
// FileInputStream fis = new FileInputStream("a.zip");
// BufferedInputStream bis  = new BufferedInputStream(fis);
// ZipInputStream zis = new ZipInputStream(bis);

// zis.read();

// ������ ����
// - ������ �����ؼ� �ذ��� �� �ֵ��� �Ѵ�.
// - Ŭ������ �� �ϳ����� å���� �������� ����ȭ �� �� �ִ�.
//   SRP