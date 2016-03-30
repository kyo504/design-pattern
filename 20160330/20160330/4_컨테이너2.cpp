// 4_�����̳�2

#include <iostream>
using namespace std;

// ��� 1. object* ����� �����̳�
// Java, C#: Object
// Objecive C: NSObject
// MFC: CObject
// Qt:  QObject
class object {
public:
  virtual ~object() {}
};

// ���̺귯�� ���� ��� Ŭ������ object�� �ڽ��̾�� �Ѵ�.
class Dialog : public object {};
class Point : public object {};
class Rect : public object {};

class Integer : public object
{
  int value;
public:
  Integer(int v) : value(v) {}
  int getValue() { return value; }
};

struct node
{
  object* data;
  node* next;
  node(object* a, node* n) : data(a), next(n) {}
};

class slist
{
  node* head;
public:
  slist() : head(0) {}

  // node�� �����ڸ� �� Ȱ���� �ڵ� �Դϴ�.
  void push_front(object* a) { head = new node(a, head); }
  object* front() { return head->data; }
};

// ����:
// 1. Ÿ�� �������� ��������. �Ǽ��� �ٸ� Ÿ���� �־ ������ �ð��� ������
//    �߻����� �ʴ´�.

// 2. ���� ���� �� �׻� �ش� Ÿ������ ĳ�����ؾ� �Ѵ�.
// 3. ��ü�� �ƴ� ǥ�� Ÿ��(primitive type)�� ������ �� ����.
//    wrapper class�� �ʿ��ϴ�. - ǥ�� Ÿ���� ���۷��� Ÿ��
//    int - Integer
//    double - Double

// ����:
//  template �� ����ϰ� �Ǹ�, �ڵ� �޸� ���� ��尡 �ִ�.

int main()
{
  slist s;
  s.push_front(new Point);
  s.push_front(new Point);
  s.push_front(new Point);

  // s.push_front(3); // ?
  s.push_front(new Integer(3));  // auto-boxing

  // s.push_front(new Dialog);  // ??? �Ǽ�!!!!

  // int n = s.front(); - auto unboxing
  int n = static_cast<Integer*>(s.front())->getValue();

}