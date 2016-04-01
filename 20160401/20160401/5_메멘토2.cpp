// 5_Memento
// �޸��� ����: ��ü�� ���¸� ���������� �����ϰ� �����ϴ� ����

// Command: ������ ĸ��ȭ
// Memento: ��ü�� ���¸� ĸ��ȭ

#include <iostream>
using namespace std;

#include <vector>
class User
{
  int level;
  int exp;
  int gold;

  // ��ü�� ���¸� �����ϴ� �ʵ带 ĸ��ȭ�Ѵ�.
  struct Memento
  {
    int level;
    int exp;
    int gold;

    Memento(int l, int g, int e) : level(l), exp(e), gold(g) {}
  };

  vector<Memento*> memento;
public:
  User() : level(1), exp(0), gold(0) {}

  int save()
  {
    Memento* m = new Memento(level, gold, exp);
    memento.push_back(m);

    return memento.size() - 1;
  }

  void load(int token)
  {
    Memento* m = memento[token];
    level = m->level;
    exp = m->exp;
    gold = m->gold;
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

  int token = user.save();
  user.attack();

  user.load(token);

}