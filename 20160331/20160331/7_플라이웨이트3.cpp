// 7_�ö��̿���Ʈ(Flyweight) 
#include <iostream>
#include <string>

using namespace std;

#include <Windows.h>  // Sleep(ms)

// ���� ���丮 �޼ҵ� - �������� �Ѱ�
// 1. ������ �̸��� ������ Ŭ���� �̸��� �����ϴ�.
//     Image(string path), Image(string url)
//   - �����ε��� �Ѱ踦 �غ��� �� �ִ�.

// 2. ���� �������� ������ �� �ִ�.
//    Color(int r, int g, int b) {}
//    static Color* newRedColor() 
//    { return new Color(255, 0, 0); }

//    Color* red = new Color(255, 0, 0);
//    Color* red = Color::newRedColor();

// 3. ��ü�� �����ϴ� ��å�� ������ �� �ִ�.
//    - new: ���ο� ��ü�� �����Ѵ�.
//    - ���� ���丮 �޼ҵ�: �̱���, �ö��̿���Ʈ, ������ �̱���


// 4. Ȱ��
// List<Integer> arr = new ArrayList<>();
// for (int i = 0 ; i < 100 ; ++i)
//    arr.add(i); -> arr.add(Integer.valueOf(i));

//-------------------------------------------------------------


// 2. ���� ���丮 �޼ҵ� - Effective Java
//   ObjectiveC - ���� ������
//  : ���� ��� ���� ���丮 �޼ҵ带 ���ؼ� �ش��ϴ� ������
//    �ذᰡ���ϴ�.

// �߿�: ��ü�� �Һ� ��ü�� �����ؾ� �Ѵ�.


#include <map>
class Image
{
  string url;
  static map<string, Image*> cache;
public:
  static Image* imageWithURL(const string& url)
  {
    if (cache[url] == 0)
      cache[url] = new Image(url);

    return cache[url];
  }

  void draw()
  {
    cout << "Draw Image : " << url << endl;
  }

private:
  Image(const string& s) : url(s)
  {
    cout << "Loading from " << url << endl;
    Sleep(3000);
  }
};

map<string, Image*> Image::cache;


int main()
{
  Image* image1 = Image::imageWithURL("http://www.a.com/a.png");
  image1->draw();

  Image* image2 = Image::imageWithURL("http://www.a.com/a.png");
  image2->draw();
}



