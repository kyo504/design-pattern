// 4_���ڷ����� ����
#include <iostream>
using namespace std;

class Ticket
{
public:
  void print()
  {
    cout << "���� ����ȸ - 2016.12.25" << endl;
  }
};

// ���: ���� Ŭ������ ����� �߰��� �� �ֽ��ϴ�.
class Ad1 : public Ticket
{
public:
  void print()
  {
    Ticket::print();                 // ���� ����� ���
    cout << "�ڵ��� ����" << endl;   // ��� �߰�
  }
};

class Ad2 : public Ad1
{
public:
  void print()
  {
    cout << "TV ����" << endl;
    Ad1::print();
  }
};

// ����� ���� ����� �߰�
// - ���� ������ ������� ���Ŀ�, �䱸 ������ ���濡 �����ϱ� ��ƴ�.
// - ����� ���� �ð��� ������ �ϴ� ���� �Ұ����ϴ�.
//    : ������ ����� �߰�

int main()
{
  Ad2 t;
  t.print();
}


