// 7_�ö��̿���Ʈ2(Flyweight) 
#include <iostream>
#include <string>

using namespace std;

#include <Windows.h>  // Sleep(ms)

// �ö��̿���Ʈ ����
// �ǵ� : �Ӽ��� ������ ��ü�� ��������!



class Image
{
  string url;

  Image(const string& s) : url(s)
  {
    cout << "Loading from " << url << endl;
    Sleep(3000);
  }
public:
  void draw()
  {
    cout << "Draw Image : " << url << endl;
  }

  friend class ImageFactory;
};

// �����ϴ� ���
// 1. ���丮: ��ü�� ����� ��Ȱ�� �����ϴ� ��

// Image ��ü�� ����� ����
// - ��ü�� ������ �� ������ �߾� ���������� ������ �� �ִ�.
#include <map>
class ImageFactory
{
  // ������ �̱����� ��찡 ����.
  map<string, Image*> cache;
public:
  Image* createImage(const string& url)
  {
    if (cache[url] == 0)
      cache[url] = new Image(url);

    return cache[url];
  }

  static ImageFactory& getInstance() {
    static ImageFactory instance;
    return instance;
  }


private:
  ImageFactory() {}
  ImageFactory(const ImageFactory&) = delete;
  void operator=(const ImageFactory&) = delete;
};

int main()
{
  ImageFactory& factory = ImageFactory::getInstance();

  Image* image1 = factory.createImage("http://www.a.com/a.png");
  image1->draw();

  Image* image2 = factory.createImage("http://www.a.com/a.png");
  image2->draw();
}



