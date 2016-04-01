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

// Image*�� �ٷ� ����ϸ� ���� ����� �Ź� �����ؾ� �Ѵ�.
// �����ϹǷ� ���� ����� �ڵ����� �������ִ� Ŭ������ ������.
class ImageProxy
{
  Image* ptr;
public:
  ImageProxy(Image* p) : ptr(p) { ptr->addRef(); } // ��Ģ 1.
  ImageProxy(const ImageProxy& p) : ptr(p.ptr)
  {  ptr->addRef();  }   // ��Ģ 2.

  ~ImageProxy() { ptr->release(); }   // ��Ģ 3.
};

int main()
{
  ImageProxy p1 = new Image;
  ImageProxy p2 = p1;
}


#if 0
int main()
{
  Image* p1 = new Image;  // ��Ģ 1. ��ü�� ����� ���� ��� ����
  p1->addRef();

  Image* p2 = p1;     // ��Ģ 2. �����͸� �����ϸ� ���� ��� ����
  p2->addRef();

  p1->release();      // ��Ģ 3. ��ü ������ ��� �� ���� ��� ����
  p2->release();
}
#endif