// 7_�ö��̿���Ʈ(Flyweight) 
#include <iostream>
#include <string>

using namespace std;

#include <Windows.h>  // Sleep(ms)

// �ö��̿���Ʈ ����
// �ǵ� : �Ӽ��� ������ ��ü�� ��������!

// �����ϴ� ���
// 1. ���丮
// 2. ���� ���丮 �޼ҵ�


class Image
{
  string url;
public:
  Image(const string& s) : url(s)
  {
    cout << "Loading from " << url << endl;
    Sleep(3000);
  }

  void draw()
  {
    cout << "Draw Image : " << url << endl;
  }
};

int main()
{
  Image* image1 = new Image("http://www.a.com/a.png");
  image1->draw();

  Image* image2 = new Image("http://www.a.com/a.png");
  image2->draw();
}



