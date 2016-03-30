// 3_RTTI3
#include <iostream>
#include <string>
using namespace std;

struct CRuntimeClass
{
  string name;
  string author;
  string version;
};

#define AAA XXX

// ��ũ�� ����
// 1. ##: ��ū �ձ�
// 2. # : ��ū ���ڿ�ȭ

// �������� ��ũ�� �Լ��� �����ؾ� �Ѵ�.
// => ��ũ�� ġȯ�� ���� ����ϱ� �����̴�.
// => Linux Kernel
// => MODULE_LINCENSE ��ũ�θ� �м��ϸ� �˴ϴ�.

// �������� ��� Ŭ������ �Ʒ� ��Ģ�� ���Ѿ� �մϴ�.
// 1. ��� Ŭ�������� ���� ��� ������ CRuntimeClass �� �־�� �Ѵ�.
// 2. ���� �̸��� "classŬ�����̸�" ���� �Ѵ�.
// 3. ���� ������ �����ϴ� �����Լ� GetRuntimeClass()�� �־�� �Ѵ�.
// �� ��Ģ�� ��ũ��ȭ �մϴ�.
#define DECLARE_DYNAMIC(classname)                                \
  public:                                                         \
  static CRuntimeClass class##classname;                          \
  virtual CRuntimeClass* GetRuntimeClass();

#define IMPLEMENT_DYNAMIC(classname)                              \
  CRuntimeClass classname::class##classname = { #classname };     \
  CRuntimeClass* classname::GetRuntimeClass()                     \
  { return &class##classname; }

// Ŭ���� �̸����� static ������ RuntimeClass ��� ��ũ��
#define RUNTIME_CLASS(classname)    &(classname::class##classname)

//-------------------------------

class Animal
{
  DECLARE_DYNAMIC(Animal)
};
IMPLEMENT_DYNAMIC(Animal)

class Dog : public Animal
{
  DECLARE_DYNAMIC(Dog)
};
IMPLEMENT_DYNAMIC(Dog)


void foo(Animal* p)
{
  if (p->GetRuntimeClass() == RUNTIME_CLASS(Dog))
    cout << "p�� Dog�Դϴ�. " << endl;
}
int main()
{
  Animal a; Dog d;
  foo(&a); foo(&d);
}
