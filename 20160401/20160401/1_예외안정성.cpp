// 1_���� ������
#include <iostream>
using namespace std;

// 1. �����ڿ��� ���и� �˸��� ����� ���� �ۿ� ����.
// 2. �����ڿ��� ���ܰ� �߻� �ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.

// ��� 1.	�����ڿ��� �ڿ��� �Ҵ����� ���� �ڿ� �Ҵ� ���� �Լ��� ��������.
//			Two Phase Constructor - 2�� ������ ȣ��

class Test
{
  int* p1;
  int* p2;
public:
  Test()
  {
    p1 = new int;
    throw std::bad_alloc;
    p2 = new int;   // �� ���� �޸𸮰� �����߽��ϴ�. � ������ �������?
                    // �޸𸮰� �����ϸ� bad_alloc �̶�� ���ܰ� �߻��մϴ�.
  }

  ~Test()
  {
    delete p1;
    delete p2;
  }
};

int main()
{
  try
  {
    Test t;
  }
  catch (...) 
  {

  }

}

