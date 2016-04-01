// 1_���� ������
#include <iostream>
using namespace std;

// 1. �����ڿ��� ���и� �˸��� ����� ���� �ۿ� ����.
// 2. �����ڿ��� ���ܰ� �߻� �ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.

// ��� ���� - ���� ������
// - Exceptional C++
// - More Exception C++
// - Exceptional C++ Style

// ���� ������(Exception safety)
// 1. ���� ����: ���ܰ� ����.
// 2. ���� ����: ���ܰ� �߻��ص� ���� ���, ��ü ���´� ���� �߻������� �����ȴ�. 
//             => STL

// 3. �⺻ ����: ���ܰ� �߻��ص� �ڿ� ������ ����. �� ��ü ���´� �� �� ���� ������
//               ����� �Ұ����ϴ�.


#include <memory>  // unique_ptr

class Image
{
public:
  Image() { cout << "Image ����" << endl; }
  ~Image() { cout << "Image �ı�" << endl; }
};

class Test
{
  unique_ptr<Image> p1;
  unique_ptr<Image> p2;
public:
  // ��� ������ Ÿ���� ��ü Ÿ���̶��, �����ڿ��� ���ܰ� �߻��Ͽ��� ���
  // ��� ������ �Ҹ����� ȣ���� ǥ�ؿ����� �����ϰ� �ִ�.
  Test() : p1(new Image), p2(new Image)
  {
    throw std::bad_alloc();
    // �� ���� �޸𸮰� �����߽��ϴ�. � ������ �������?
    // �޸𸮰� �����ϸ� bad_alloc �̶�� ���ܰ� �߻��մϴ�.
  }

  ~Test()
  {
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

