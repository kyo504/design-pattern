#include <iostream>
using namespace std;

// ���� ����� �̱���
// - �ȵ���̵� �����ӿ�ũ�� ����ϰ� �ִ� �̱��� �Դϴ�.

class Mutex
{
public:
  void lock() { cout << "Mutex lock" << endl; }
  void unlock() { cout << "Mutex unlock" << endl; }

  // ����ȭ ��ü ���� ���ܰ� �߻��ϸ� ������� Ȯ���� �ֽ��ϴ�.
  // ������/�Ҹ��ڷ� ����ȭ ��ü�� �����ϸ� ���ϴ�.
  // RAII(Resource Acqusion Is Initialize) ��� ���
  // - ���Ǽ�, ���� ������
  // http://occamsrazr.net/tt/297 ����

  class AutoLock
  {
    Mutex& mLock;
  public:
    inline AutoLock(Mutex& m) : mLock(m) { mLock.lock();   }
    inline ~AutoLock()                   { mLock.unlock(); }
  };
};

// #include <mutex>  // lock_guard


class Cursor
{
private:
  Cursor() {}
  Cursor(const Cursor&);
  void operator=(const Cursor&);

  static Mutex   sLock;
  static Cursor* sInstance;
public:
  static Cursor& getInstance()
  {
    // sLock.lock();
    // lock_guard<Mutex> al(sLock);
    Mutex::AutoLock al(sLock);

    if (sInstance == 0)
      sInstance = new Cursor;  // std::bad_alloc ���ܰ� �߻� 
                               // �� �� �ֽ��ϴ�.
    // sLock.unlock();

    return *sInstance;
  }
};

// static ��� ������ �ݵ�� �ܺο� ���Ǹ� �ؾ� �մϴ�.
Mutex   Cursor::sLock;
Cursor* Cursor::sInstance = 0;


int main()
{
  Cursor& c1 = Cursor::getInstance();
  Cursor& c2 = Cursor::getInstance();

  cout << &c1 << endl;
  cout << &c2 << endl;

}