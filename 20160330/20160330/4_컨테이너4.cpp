// 4_�����̳�4
#include <iostream>
using namespace std;

struct node
{
  void* data;
  node* next;
  node(void* a, node* n) : data(a), next(n) {}
};

class slistImpl
{
  node* head;
public:
  slistImpl() : head(0) {}

  void push_front(void* a) { head = new node(a, head); }
  void* front() { return head->data; }
};

// ��� 3. Thin Template

// slistImpl�� ���� ����ϸ� ĳ���� ������ �����ϴ�.
// ����ڰ� ���ϰ� ����� �� �ֵ��� ������ ���� �޴� �ڽ� Ŭ������ 
// ���ø����� ��������.
template <typename T>
class slist : private slistImpl
{
public:
  inline void push_front(const T& a)
  {
    //  const T& -> const T*
    slistImpl::push_front(const_cast<T*>(&a));
  }

  inline T& front()
  {
    // void* -> T* -> T&
    return *static_cast<T*>(slistImpl::front());
  }
};

int main()
{
  slist<int> s;
  s.push_front(10);
  s.push_front(20);
  s.push_front(30);

  cout << s.front() << endl;
}