// 6_����2
// State Pattern: ���¿� ���� ������ ����
//   - ���� ���� �� �θ� ���ȴ�.
#include <iostream>
using namespace std;

// ��� 1. �������� ������ ���� ���� �б�

class Hero
{
  int state;
public:
  void setState(int s) {
    state = s;
  }


  // ������: OCP�� ������ �� ����.
  //  - �ű� �������� �߰��Ǹ� ���Ǻб⹮�� �߰��Ǿ�� �Ѵ�.
  void run() 
  {
    if (state == 1)
      cout << "run" << endl;
    else if (state = 2)
      cout << "fast run" << endl;
  }

  void attack() { cout << "attack" << endl; }
};

int main()
{
  Hero hero;
  hero.run();
  hero.attack();
}