#include <iostream>
#include <string>
using namespace std;
// 3_RTTI2
// C++�� ���� �����ӿ�ũ���� ��ü������ RTTI�� ������ 
// ���� �����ؼ� ����ϰ� �ֽ��ϴ�.
// MFC, Qt, Android ...

// ��ü�� Ŭ������ ������ ������ �����ؾ� �Ѵٸ� -> ���� ��� ����

// RTTI�� �ٽ��� type_info�Դϴ�. => ���� ��� ����
struct CRuntimeClass
{
  string name;
  string author;
  string version;
};

// �������� ��� Ŭ������ �Ʒ� ��Ģ�� ���Ѿ� �մϴ�.
// 1. ��� Ŭ�������� ���� ��� ������ CRuntimeClass �� �־�� �Ѵ�.
// 2. ���� �̸��� "classŬ�����̸�" ���� �Ѵ�.
// 3. ���� ������ �����ϴ� �����Լ� GetRuntimeClass()�� �־�� �Ѵ�.
class Animal
{
public:
  static CRuntimeClass classAnimal;
  virtual CRuntimeClass* GetRuntimClass()
  { return &classAnimal; }
};

CRuntimeClass Animal::classAnimal = { "Animal" };

class Dog : public Animal
{
public:
  static CRuntimeClass classDog;
  virtual CRuntimeClass* GetRuntimClass()
  { return &classDog; }
};

CRuntimeClass Dog::classDog = { "Dog" };

void foo(Animal* p)
{
  if (p->GetRuntimClass() == &Dog::classDog)
    cout << "p�� Dog�Դϴ�. " << endl;
}


int main()
{
  Animal a; Dog d;
  foo(&a); foo(&d);
}
