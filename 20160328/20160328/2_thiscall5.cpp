// 2_thiscall5.cpp

#include <iostream>
#include <string>
#include <map>
using namespace std;

//class Clock;	// ���� ���� : �ڿ� ����Ǿ� �ֱ� ������ �����Ϸ����� �˷���� �Ѵ�. - ������ ������ ��� �����ʹ� ��� ����
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

// static ��� ������ �ܺ� ���Ǹ� �ؾ� �մϴ�. (�ҽ� ����)
map<int, Clock*> Clock::this_map;

int main()
{
	Clock c1("AAA");	// 1�ʿ� �� ���� �̸��� ����ؾ� �Ѵ�.
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