// 6_상태4// 6_상태
// State Pattern: 상태에 따른 동작의 변경
//   - 게임 만들 때 널리 사용된다.

// 방법 3. 변하는 것을 인터페이스 기반 다른 클래스로 분리

#include <iostream>
using namespace std;

// 상태에 따른 동작을 정의한 인터페이스
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}
};


class Hero
{
  IState* state;
public:
	Hero() : state(nullptr) {}
	void setState(IState* p) { state = p; }

	void run()		{ state->run(); }
	void attack()	{ state->attack(); }
};

class NormalState : public IState
{
public:
	virtual void run() { cout << "run" << endl; }
	virtual void attack() { cout << "attack" << endl; }
};

class FastState : public IState
{
public:
	virtual void run() { cout << "fast run" << endl; }
	virtual void attack() { cout << "fast attack" << endl; }
};

// 공통성과 가변성의 분리
// - 디자인 패턴에서 변하는 것을 인터페이스 기반의 다른 클래스로 분리하는 패턴은 2가지 입니다.
// 1. 전략 패턴 - 변하는 것이 정책이나 알고리즘
// 2. 상태 패턴 - 변하는 것이 상테에 따른 동작

int main()
{
	NormalState ns; FastState fs;

	Hero hero;
	hero.setState(&ns);
	hero.run();
	hero.attack();

	hero.setState(&fs);
	hero.run();
	hero.attack();
}
