#include <iostream>
using namespace std;
// 3_RTTI
// 1. ����: ���� �ð��� p�� ������ � ��ü�� ����Ű���� �����ϴ� ��
//    Run Time Type Information
// Java, C#: Reflection, ObjC: Instropection

// 2. ���� �Լ� ���̺�� �����Ǵ� type_info�� ����ϹǷ� ���� �Լ� ���̺���
//    �����ؾ� ����� �����Ѵ�.

class Animal 
{
public:
  virtual ~Animal() {}
};
class Dog : public Animal
{
public:
  int color;
};

void foo(Animal* p)
{
  // �ٿ� ĳ����
  // 1) static_cast: ������ Ÿ�� ĳ����
  //  ������: �߸��� �ٿ� ĳ������ ������ �� ����.
  // Dog* pDog = static_cast<Dog*>(p);
  //  ����: ĳ������ ������ Ÿ�ӿ� ����ǹǷ� ���� ���ϰ� ����.
  //        �ǵ��� ���谡 �ǵ��� �ڽĸ��� ������ �Ǿ� �ִٸ�
  //        �ݵ�� static_cast�� ����ؾ� �Ѵ�.

  Dog* pDog = dynamic_cast<Dog*>(p);
  cout << pDog << endl;
  // pDog->color = 20;
  
  // 2) dynamic_cast: ��Ÿ�� ĳ����
  //  ����: ���������� RTTI�� �̿��Ͽ� �����ǹǷ�, �߸��� �ٿ� ĳ������
  //        ������ �� �ִ�. �� �߸��� ĳ������ NULL�� �����Ѵ�.
  //  ����: ������. �� �ʿ��Ҷ��� ����ؾ� �Ѵ�.
}

int main()
{
  Animal a; Dog d;
  foo(&a); foo(&d);
}




#if 1
void foo(Animal* p)
{
  cout << typeid(*p).name() << endl;
  // � �̸��� ��������� ���� �κ��� ǥ�ؿ� ���ǵǾ� ���� �ʽ��ϴ�.

  // ������ Ÿ���� ������ �� �Ʒ��� ���� ����ϸ� �˴ϴ�.
  if (typeid(*p) == typeid(Dog)) {
    //...
  }

  // ���� p�� Dog��� color�� �����ϰ� �ʹ�.
  // �� Ŭ������ ���� �Լ��� �������� �ʴ´ٸ�, ������ �ð���
  // p�� Ÿ������ type_info ����ü�� ����� ���� �ڵ� �����Ѵ�.
  const type_info& t1 = typeid(*p);     // typeid(��ü)
  const type_info& t2 = typeid(Dog);    // typeid(Ŭ����)

                                        // �����ϰ� �ʹٸ�
  if (t1 == t2)
    cout << "p�� Dog �Դϴ�." << endl;
  else
    cout << "p�� Animal �Դϴ�." << endl;
}
#endif

