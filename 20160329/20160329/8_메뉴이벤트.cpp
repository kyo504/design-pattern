// 8_�޴��̺�Ʈ1

#include <iostream>
using namespace std;

class MenuItem
{
public:
  MenuItem() {}

  virtual void command()
  {
    // �޴��� ���õ� ����� �ٽ� �ܺο� �˷��� �Ѵ�.
    // "��ü�� �ܺη� �̺�Ʈ�� �߻��Ѵ�." ��� ǥ��
  }
};

int main()
{
  MenuItem m1;
  m1.command();
}
