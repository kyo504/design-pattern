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

// 반드시 동적 모듈 안에서 객체를 생성하는 방법을 제공해주어야 합니다.
// - SampleGraph 라는 이름은 현재 DLL을 만드는 사람만 알고 있습니다.
// - 프로그램 내부에서는 절대 이름을 사용하면 안됩니다.

// 반드시 DLL내부에서 자신이 만든 크래스의 객체를 생성해주어야 합니다.
// - 함수 하나를 약속합니다.

extern "C"
__declspec(dllexport) // 윈도우에서 DLL 내부 심볼을 공개하는 방법.
IObserver* CreateGraph()
{
	return new SampleGraph;
}
