// 5_�̱���
#include <iostream>
using namespace std;

// ���� : ���� �Ѱ��� ��ü�� ����� �ְ� ��𿡼��� ������ ������� ��ü��
//        ���� �� �ְ� �ϴ� ����.
// - Chromium, Webkit, Firefox

class Cursor
{
private:
  Cursor() {}           // ��Ģ 1. private ������

  // ��Ģ 3. ����� ���� ����
  //  �ٽ�: ���� �Ѵ�. ������ ����!
  // Cursor(const Cursor&);
  // void operator=(const Cursor&);

  // ���� ���� ���� ����� C++11���� ����ȭ �Ǿ����ϴ�.
  // "delete function" �̶�� ����.
  Cursor(const Cursor&) = delete;
  void operator=(const Cursor&) = delete;

  // static final Cursor INSTANCE = new Cursor(); - Java 1.5
  // lazy initialization

public:
  // ��Ģ 2. ���� �Ѱ��� ����� ���� ��� �Լ�
  // - ���̾�� �̱���
  static Cursor& getInstance()
  {
    static Cursor instance;
    // Cursor s = instance;

    return instance;
  }
};

// Cursor c;
// - ������ �Ҹ��� ������ ��Ȯ�ϰ� ���ǵǾ� ���� �ʴ�.

int main()
{
  Cursor::getInstance();

  Cursor& c1 = Cursor::getInstance();
  Cursor& c2 = Cursor::getInstance();

  cout << &c1 << endl;
  cout << &c2 << endl;
}





