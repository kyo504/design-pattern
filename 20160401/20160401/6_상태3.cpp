// 6_����3
// State Pattern: ���¿� ���� ������ ����
//   - ���� ���� �� �θ� ���ȴ�.
#include <iostream>
using namespace std;


// ��� 2. ���ϴ� ���� �����Լ��� �и�
//       - item�� ���� ���ϴ� ���� -> ���� �Լ�
class Hero
{
  int state;
public:
  int gold;

  virtual void run() { cout << "run" << endl; }
  virtual void attack() { cout << "attack" << endl; }
};

// �������� ȹ�濡 ���� ������ �����ϱ� ���� ����� �����ϸ� �ȴ�.
class FastItemHero : public Hero
{
public:
  virtual void run() { cout << "Fast run" << endl; }
  virtual void attack() { cout << "Fast attack" << endl; }
};

int main()
{
  Hero normal; FastItemHero fast;
  Hero* hero = &normal;  // �ʱ� ����
  hero->attack();
  hero->run();
  
  hero->gold += 100;

  //..... ������ ȹ��
  // ���� �� �ƴ϶� ���µ� ����ȴ�. gold�� ���� �Ǿ�� �Ѵ�.
  hero = &fast;

  hero->attack();
  hero->run();
}