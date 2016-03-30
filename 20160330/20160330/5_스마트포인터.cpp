// 5_����Ʈ������
#include <iostream>
using namespace std;

class Car
{
public:
  Car()  { cout << "�ڿ� ����" << endl; }
  ~Car() { cout << "�ڿ� ����" << endl; }

  void go() { cout << "Car go" << endl; }
};

// ����Ʈ ������
// ����: ������ ��ü�� �ٸ� ��ü�� �������� ��Ȱ�� �����ϴ� ��.
// ��������: -> �� * �����ڸ� �������ؼ� ������ó�� ���̰� �����.
// ����: ��¥ �����Ͱ� �ƴ϶� ��ü�̴�.
//       ����/����/����/�Ҹ��� ��� ������ ������ �� �ִ�.
// Ȱ��: ��ǥ�� Ȱ���� �Ҹ��ڿ����� �ڵ� ���� ����̴�.

// C++ ǥ�ؿ����� �̹� �پ��� ��å�� ������ �ִ� ����Ʈ �����͸� �����ϰ� �ֽ��ϴ�.
//  C++98/03 - auto_ptr
//  C++11/14 - unique_ptr, shared_ptr, weak_ptr, auto_ptr(deprecated)

template <typename T>
class Ptr
{
  T* obj;
public:
  inline T* operator->() { return obj; }
  inline T& operator*()  { return *obj; }

  inline Ptr(T* p = 0) : obj(p) {}
  inline ~Ptr()
  {
    delete obj;
  }
};

int main()
{
  Ptr<Car> p = new Car;

  p->go();
  (*p).go();
}



#if 0
int main()
{
  Car* p = new Car;

  p->go();
  (*p).go();

  delete p;
}
#endif








