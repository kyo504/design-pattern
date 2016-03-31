// 2_������

#include <iostream>
#include <vector>
using namespace std;

// 1. ������ ���� ����: �ϳ��� �̺�Ʈ�� ���� ��ü�� �����ϴ� ����
struct IObserver
{
	virtual void onUpdate(void* data) = 0;
	virtual ~IObserver()
};

// ������ ���: ǥ - (���̶�� �θ��ϴ�.)
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

