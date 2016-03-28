// 2_thiscall5.cpp

#include <iostream>
#include <string>
#include <map>
using namespace std;

//class Clock;	// 전방 선언 : 뒤에 선언되어 있기 때문에 컴파일러에게 알려줘야 한다. - 완전한 선언이 없어도 포인터는 사용 가능
//map<int, Clock*> this_map;

#include "ioacademy.h"
using namespace ioacademy;

class Clock
{
	string name;
	static map<int, Clock*> this_map;

public:
	Clock(string s) : name(s) {};

	void start(int ms) {
		int id = IoSetTimer(ms, timerHandler);
		this_map[id] = this;
	};

	static void timerHandler(int id)
	{
		Clock* self = this_map[id];
		cout << self->name << endl;
	}
};

// static 멤버 변수는 외부 정의를 해야 합니다. (소스 파일)
map<int, Clock*> Clock::this_map;

int main()
{
	Clock c1("AAA");	// 1초에 한 번씩 이름을 출력해야 한다.
	Clock c2("\nBBB");

	c1.start(1000);
	c2.start(500);
}

#if 0
void foo(int id)
{
	cout << "foo: " << id << endl;
}

int main()
{
	int n1 = IoSetTimer(1000, foo);
	int n2 = IoSetTimer(500, foo);

	IoProcessMessage();
}
#endif