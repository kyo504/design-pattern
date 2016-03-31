// SampleGraph.cpp
#include "IObserver.h"

#include <iostream>
using namespace std;

class SampleGraph : public IObserver
{
public:
	virtual void onUpdate(void* p)
	{
		int* data = static_cast<int*>(p);
		cout << "******** Pie Graph *********" << endl;
		for (int i = 0; i < 5; ++i)
			cout << i << " : " << data[i] << endl;
	}
};

// �ݵ�� ���� ��� �ȿ��� ��ü�� �����ϴ� ����� �������־�� �մϴ�.
// - SampleGraph ��� �̸��� ���� DLL�� ����� ����� �˰� �ֽ��ϴ�.
// - ���α׷� ���ο����� ���� �̸��� ����ϸ� �ȵ˴ϴ�.

// �ݵ�� DLL���ο��� �ڽ��� ���� ũ������ ��ü�� �������־�� �մϴ�.
// - �Լ� �ϳ��� ����մϴ�.

extern "C"
__declspec(dllexport) // �����쿡�� DLL ���� �ɺ��� �����ϴ� ���.
IObserver* CreateGraph()
{
	return new SampleGraph;
}
