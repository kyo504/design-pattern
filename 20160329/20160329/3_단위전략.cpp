#include <iostream>
using namespace std;

// ����ȭ ���θ� �������̽� ����� �ٸ� Ŭ������ �и�����.
// ����: ���� �ð��� ��å�� ��ü�� �� �ִ�. setSync
// ����: ���� �Լ� ����̹Ƿ� ������.
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

class SingleThread : public ISync
{
public:
	virtual void lock() {}
	virtual void unlock() {}
};

class MultiThread : public ISync
{
public:
	virtual void lock() { cout << "mutex lock" << endl; }
	virtual void unlock() { cout << "mutex unlock" << endl; }
};

template <typename T>
class List
{
	ISync* pSync;
public:
	List() : pSync(0) {
		if (pSync == 0)
			pSync = new SingleThread();
	}
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a) {
		pSync->lock();
		// ...
		pSync->unlock();
	}
};

List<int> st; // ���� ����

int main()
{
	SingleThread sthread;
	st.setSync(&sthread);

	st.push_front(10);
}