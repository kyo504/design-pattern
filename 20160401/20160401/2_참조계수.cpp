// 2_������� - �ſ� �߿��մϴ�.

#include <iostream>
using namespace std;

// ��ü�� ������ ���� ����� �����ϴ� ��찡 �����ϴ�.
class Image
{
  int mCount;
public:
  Image() : mCount(0) {}
  ~Image() { cout << "Image �ı�" << endl; }

  void addRef() { ++mCount; }
  void release()
  {
    if (--mCount == 0)
      delete this;
  }
};

int main()
{
  Image* p1 = new Image;  // ��Ģ 1. ��ü�� ����� ���� ��� ����
  p1->addRef();

  Image* p2 = p1;     // ��Ģ 2. �����͸� �����ϸ� ���� ��� ����
  p2->addRef();

  p1->release();      // ��Ģ 3. ��ü ������ ��� �� ���� ��� ����
  p2->release();
}