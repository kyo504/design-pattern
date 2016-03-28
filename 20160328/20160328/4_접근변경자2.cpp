// 4_접근변경자2.cpp
#include <iostream>
using namespace std;

// 리스트가 이미 있습니다.
#include <list>

// 그런데 클라이언트가 스택을 요구한다.
// 1. stack을 자지 만들어 주자.
// 2. 리스트를 한 쪽으로 사용하면 stack이다. list를 재사용하자

// Adepter Pattern : 기존 클래스의 인터페이스(함수 이름)을 변경해서 사용자가 요구하는 새로운 클래스 처럼 보이게 하는 패턴

// 라이브러리는 쉽게 사용할 수 있도록 만들어양 한다.
// 잘못 사용하기 어렵게 만들어야 한다.



template <template T>
class stack : public list < T >
{
public:
	void push(const T& a)	{ push_back(a); }
	void pop()				{ pop_back(); }
	T&   top()				{ return back(); }
};

int main()
{
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push_back(300);

	cout << s.top() << endl;
}
