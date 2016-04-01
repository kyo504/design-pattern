// ����
// -> ������ ���������� ǥ���� �޶����� ��ü�� ���� ��
// -> ��ü ����

// -> �������� ���ڰ� ������
#include <iostream>
#include <string>
using namespace std;

// ��� 2. Beans Pattern
//    
class UserInfo
{
public:
  UserInfo() {}

  void setId(string s) { id = s; }
  void setAddress(string s) { address = s; }
  void setLevel(int a) { level = a; }
  void setGold(int a) { gold = a; }
  void setCash(int a) { cash = a; }

private:
  string id;          // �ʼ� ����
  string address;
  int level;                // ���� ����
  int gold;
  int cash;
};

// ���: �⺻ �����ڸ� ȣ���Ͽ� ��ü�� ������ ��, ���� �Լ��� ���ؼ�
//       �� �ʵ带 �ʱ�ȭ�Ѵ�.

// ����: �������� ����.
// ����: - ��ü�� �ϰ����� ������.
//       - ��ü�� ������ ���Ŀ� �ٷ� ����ϴ� ���� �ƴ϶�
//       - ������ �ʱ�ȭ ������ ���� ���ľ� �Ѵ�.
//       - �ʼ� ������ ������ ������ �� ����.
//       - �Һ� ��ü�� ���� �� ����.
//       - ������ �������� ���� �߰����� ����� �ʿ��ϴ�.

int main()
{
  UserInfo ui;    // �ҿ��� ��ü
  ui.setId("chansik.yun");
  ui.setAddress("����");
  ui.setLevel(10);
  ui.setGold(1000);
  ui.setCash(100);
}