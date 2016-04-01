#include <iostream>
using namespace std;

#include <memory>

// ��ȯ ����
// => ���� ������ ����� ���� ������ ������ �����ϰ� ������ �� �־��
//    �Ѵ�. => ������

// Node p = new Node();  ->  ���� ����
// WeakReference<Node> wp = new WeakReference<>(new Node()); 
// -> ���� ����

struct node
{
  ~node() { cout << "node �ı�" << endl; }
  weak_ptr<node> next;
};

int main()
{
  shared_ptr<node> p1(new node);
  shared_ptr<node> p2(new node);

  p1->next = p2;
  p2->next = p1;

  shared_ptr<node> p = p1->next.lock(); 
  // ������� �������� ���� �Ѵ�.


}