#include <iostream>
using namespace std;

// 4_���ٺ�����3.cpp
#include <list>

// S/W�� ������ ��Ӱ� ������ �ֽ��ϴ�. => ������ ���� ���� ����.
// stack adapter��� �θ���.

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