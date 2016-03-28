#include <iostream>
using namespace std;

// 4_접근변경자3.cpp
#include <list>

// S/W의 재사용은 상속과 포함이 있습니다. => 포함이 좋을 때가 많다.
// stack adapter라고 부른다.

#include <deque>
#include <vector>

template <typename T, typename C = deque<T> >
class stack
{
	C st;
public:
	void push(const T& a)	{ st.push_back(a); }
	void pop()				{ st.pop_back(); }
	T& top()				{ return st.back(); }
};

int main()
{
	stack<int> s;
	stack<int, vector<int>> s2;
	s.push(10);
	s.push(20);

	cout << s.top() << endl;
}