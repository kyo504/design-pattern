// 5_Memento
// �޸��� ����: ��ü�� ���¸� �����ϰ� �����ϴ� ����

#include <iostream>
using namespace std;

class User
{
  int level;
  int exp;
  int gold;
public:
  User() : level(1), exp(0), gold(0) {}

  int getLevel() { return level; }
  int getExp() { return exp; }
  int getGold() { return gold; }

  void load(int l, int e, int g)
  {
    level = l;
    exp = e;
    gold = g;
  }

  void attack()
  {
    ++level;
    exp += 100;
    gold += 1000;
  }
};

int main()
{
  User user;
  user.attack();
  //...
  int g = user.getGold();
  int l = user.getLevel();
  int e = user.getExp();

  //.....

  user.load(l, g, e);
}