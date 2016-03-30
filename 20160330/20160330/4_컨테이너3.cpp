// 컨테이너3

#include <iostream>
using namespace std;
// 4_컨테이너
// 컨테이너를 설계하는 기술
// - 단일 연결리스트 기반의 컨테이너

// 인자를 전달할 때			표준 타입					객체 타입
// call by value			void foo(int n)			void foo(const AAA& n)
// call by referene			void foo(int& n)		void foo(AAA& n)

//							T - 표준 타입 또는 객체 타입도 될 수 있다.

template <typename T>
struct node
{
  T data;
  node* next;
  node(const T& a, node* n) : data(a), next(n) {}
};

template <typename T>
class slist
{
  node<T>* head;
public:
  slist() : head(0) {}

  // node의 생성자를 잘 활용한 코드 입니다.
  void push_front(const T& a) { head = new node<T>(a, head); }
  T& front() { return head->data; }
};

// 장점: 타입 안정성이 뛰어나고 표준 타입 뿐 아니라 객체도 저장 가능하다. 꺼낼 때 캐스팅이 필요없다.
// 단점: template 이므로 여러가지 타입에 사용하면 list의 기계어 코드가 많아진다. 코드 메모리 오버헤드가 있다.

int main()
{
  slist<int> s;
  s.push_front(10);
  s.push_front(20);
  s.push_front(30);

  cout << s.front() << endl;
}