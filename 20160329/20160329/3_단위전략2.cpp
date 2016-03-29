#include <iostream>
using namespace std;

// 3_��������2

// ���� ����(Policy-based Design) - "Modern C++ design"
// => ��å�� ���� �ڵ带 ������ �ð��� ������ ���� ���
// => C++ ǥ�� ���̺귯���� �ٽ� ������ ���

// ����: �����Լ��� �ƴ� �ζ��� �Լ��̴�. ȣ�⿡ ���� ���� ���ϰ� ����.
// ����: ��å Ŭ������ �Լ����ƴ� ���ø� ���ڷ� ���޵ǹǷ� ����ÿ� ��å�� ��ü�ϴ� ���� �Ұ��� �Ѵ�.
//		=> ������ �� �� ��å�� �����ȴ�.!!!

// ����� ����� ���� ���� ���
template <typename T, typename ThreadModel = SingleThread>
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		lock();
		// ...
		unlock();
	}
};

class SingleThread
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class MultiThread
{
public:
	void lock() { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }
};

List<int, MultiThread> st;

int main()
{

	return 0;
}