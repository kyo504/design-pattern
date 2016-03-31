// 3_�뺸����(NotificationCenter)

#include <functional> // function
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// C++ ���� callback �� ����ϴ� ����� 2���� ����
// 1. �������̽� ����� ��ü ���
//   - �������� ������ ���� (��ü ����), ������
// 2. �Լ� ������(function<>)���� �Լ� ���
//   - �뺸 ����


void foo() { cout << "foo" << endl; }
void goo(int n) { cout << "goo : " << n << endl; }
class Dialog {
public:
  void warning() { cout << "Warning Dialog" << endl; }
};


// ������(��)�� �ִ� �뺸 ���͸� ����� ���ô�.
class NotificationCenter
{
  typedef function<void()> HANDLER;

  map<string, vector<HANDLER>> notifi_map;
public:
  void addObserver(string key, HANDLER handler)
  {
    notifi_map[key].push_back(handler);
  }

  void postNotificationWithName(string key)
  {
    vector<HANDLER>& v = notifi_map[key];
    for (HANDLER e : v)
      e();
  }

  // global ������ ������ ��������.
  // Singleton: ���� �Ѱ��� ��ü�� �����ϰ� ��𼭵� ������ ������� ������ �� �ֵ���
  //            �Ѵ�.
  static NotificationCenter& defaultCenter()
  {
    static NotificationCenter instance;
    return instance;
  }
};

// ������(Mediator) ����
// - ������ ��ü���� ���踦 �ܼ�ȭ �����ִ� Ŭ����
int main()
{
  NotificationCenter& globalCenter = NotificationCenter::defaultCenter();

  NotificationCenter nc;
  nc.addObserver("LOWBATTERY", &foo);
  nc.addObserver("LOWBATTERY", bind(&goo, 5));

  Dialog dialog;
  nc.addObserver("LOWBATTERY", bind(&Dialog::warning, &dialog));


  // ���� ���͸��� üũ�ϴ� ��⿡��
  nc.postNotificationWithName("LOWBATTERY");
}











