// 6_����4// 6_����
// State Pattern: ���¿� ���� ������ ����
//   - ���� ���� �� �θ� ���ȴ�.

// ��� 3. ���ϴ� ���� �������̽� ��� �ٸ� Ŭ������ �и�

#include <iostream>
using namespace std;

// ���¿� ���� ������ ������ �������̽�
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

// ���뼺�� �������� �и�
// - ������ ���Ͽ��� ���ϴ� ���� �������̽� ����� �ٸ� Ŭ������ �и��ϴ� ������ 2���� �Դϴ�.
// 1. ���� ���� - ���ϴ� ���� ��å�̳� �˰���
// 2. ���� ���� - ���ϴ� ���� ���׿� ���� ����

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
