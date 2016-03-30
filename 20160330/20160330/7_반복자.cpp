#include <iostream>
using namespace std;

template <typename T>
struct node
{
  T data;
  node* next;
  node(const T& a, node* n) : data(a), next(n) {}
};

// slist�� �ݺ��ڸ� �����غ��ô�.
// - �����̳��� ������ ǥ���ϴ� Ÿ��(����Ʈ ������)

template <typename T>
class slist_iterator
{
  node<T>* current;
public:
  slist_iterator(node<T>* p = 0) : current(p) {}
  
  // ==, != �� �����Ѵ�.
  inline bool operator==(const slist_iterator& t) { return t.current == current; }
  inline bool operator!=(const slist_iterator& t) { return t.current != current; }

  // ���� ��� ����
  inline T& operator*() { return current->data; }

  // �̵��ϴ� ����
  inline slist_iterator& operator++()
  {
    current = current->next;
    return *this;
  }
};

// ��� �����̳��� �����ڴ� �ڽ��� ó���� �� ������ ����Ű�� �ݺ��ڸ�
// ���� �� �ִ� ������ �����ؾ� �Ѵ�.
// begin() / end()
template <typename T>
class slist
{
  node<T>* head;
public:
  // ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� �̸� ��ӵ� ���·�
  // �ܺο� �˷��� �Ѵ�.
  typedef slist_iterator<T> iterator;

  // �ݺ��ڸ� ������ �Լ� 
  slist_iterator<T> begin() { return slist_iterator<T>(head); }
  slist_iterator<T> end()   { return slist_iterator<T>(0); }

  slist() : head(0) {}

  void push_front(const T& a) { head = new node<T>(a, head); }
  T& front() { return head->data; }
};

template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
  while (first != last && *first != value)
    ++first;

  return first;
}

int main()
{
  slist<int> s;
  s.push_front(10);
  s.push_front(20);
  s.push_front(30);

  // slist_iterator<int> p = xfind(s.begin(), s.end(), 20);

  slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
  if (p != s.end())
    cout << *p << endl;


}