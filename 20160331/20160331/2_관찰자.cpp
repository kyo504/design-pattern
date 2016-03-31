// 2_관찰자

#include <iostream>
#include <vector>
using namespace std;

// 1. 관찰자 패턴 개념: 하나의 이벤트를 여러 객체에 전파하는 패턴
struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver()
};

// 관찰의 대상: 표 - (모델이라고 부릅니다.)
class Table
{
	int data[5];

	vector<IObserver*> v;
public:
	Table(){ memset(data, 0, sizeof(data)); }
	void attach(IObserver* p) { v.push_back(p); }
	void detach(IObserver* p) {}

	void notify(void *p)
	{
		for (IObserver* e : v)
			e->onUpdate(p);
	}

	void edit()
	{
		while (1)
		{
			int index;
			cout << "index: ";
			cin >> index;
			cout << "data: ";
			cin >> data[index];

			notify(data);
		}
	}
};

class PieGraph : public IObserver
{
public:
	virtual void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "******** Pie Graph ********" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << " : " << data[i] << endl;
	}
};

class BarGraph	: public IObserver
{
public:
	virtual void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "******** Pie Graph ********" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << " : " << data[i] << endl;
	}
};

