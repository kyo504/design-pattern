// 4_���ٺ�����2.cpp
#include <iostream>
using namespace std;

// ����Ʈ�� �̹� �ֽ��ϴ�.
#include <list>

// �׷��� Ŭ���̾�Ʈ�� ������ �䱸�Ѵ�.
// 1. stack�� ���� ����� ����.
// 2. ����Ʈ�� �� ������ ����ϸ� stack�̴�. list�� ��������

// Adepter Pattern : ���� Ŭ������ �������̽�(�Լ� �̸�)�� �����ؼ� ����ڰ� �䱸�ϴ� ���ο� Ŭ���� ó�� ���̰� �ϴ� ����

// ���̺귯���� ���� ����� �� �ֵ��� ������ �Ѵ�.
// �߸� ����ϱ� ��ư� ������ �Ѵ�.



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
