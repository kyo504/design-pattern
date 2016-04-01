// 2_�������3 - �ſ� �߿��մϴ�.

#include <iostream>
using namespace std;

// ��ü�� ������ ���� ����� �����ϴ� ��찡 �����ϴ�.
class RefCountedObject
{
  int mCount;
public:
  RefCountedObject() : mCount(0) {}
  virtual ~RefCountedObject() { cout << "��ü �ı�" << endl; }

  void addRef() { ++mCount; }
  void release()
  {
    if (--mCount == 0)
      delete this;
  }
};

template <typename T>
class Ptr 
{
  T* ptr;
public:
  Ptr(T* p) : ptr(p) { ptr->addRef(); } 
  Ptr(const Ptr& p) : ptr(p.ptr)
  {
    ptr->addRef();
  }  

  ~Ptr() { ptr->release(); }  

  // ��¥ ������ó�� ������ �Ѵ�. ->, * �����ڸ� �������ؾ� �Ѵ�.
  // => ����Ʈ ������ �⺻
  T* operator->() { return ptr;  }
  T& operator*()  { return *ptr; }
};

//----------------

class Image : public RefCountedObject
{
public:
  void draw() { cout << "Image draw" << endl; }

};


// ������ ��ü�� ���� ��� ������� �����ϰ� �ʹ�.
// shared_ptr<>
// shared_ptr<Image> p(new Image);
// shared_ptr<Image> p = make_shared<Image>();

// ����Ʈ ������ - �ڿ��� ������
// - shared_ptr : ���� ��� ���           : ������ ����
// - unique_ptr : ���� ����, ������ ����   : ȥ�� ����

// Effective Modern C++ - �λ���Ʈ, ����
// unique_ptr<int> p1(new int);
// unique_ptr<int> p2 = p1;             // ����. ���� ����
// unique_ptr<int> p2 = std::move(p1);  // ������ ����, p1 -> 0

// http://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/ ����

int main()
{
  Ptr<Image> p1 = new Image;
  Ptr<Image> p2 = p1;

  p1->draw();
  p2->draw();

}