// 6_����
// State Pattern: ���¿� ���� ������ ����
//   - ���� ���� �� �θ� ���ȴ�.
#include <iostream>
using namespace std;

class Hero
{
  int state;
public:
  void run() { cout << "run" << endl; }
  void attack() { cout << "attack" << endl; }
};

int main()
{
  Hero hero;
  hero.run();
  hero.attack();
}