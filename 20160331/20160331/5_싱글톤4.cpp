// 5_�̱���4
#include <iostream>
using namespace std;

class Mutex
{
public:
  void lock() { cout << "Mutex lock" << endl; }
  void unlock() { cout << "Mutex unlock" << endl; }

  class AutoLock
  {
    Mutex& mLock;
  public:
    inline AutoLock(Mutex& m) : mLock(m) { mLock.lock(); }
    inline ~AutoLock() { mLock.unlock(); }
  };
};

// �̱����� ����� ������ �׻� �����մϴ�.
// �θ� Ŭ������ �����ϸ� ���ϰ� ����� �� �ֽ��ϴ�.
template <typename TYPE>
class Singleton
{
protected:
  Singleton() {}

private:
  Singleton(const Singleton&);
  void operator=(const Singleton&);

  static Mutex   sLock;
  static TYPE* sInstance;
public:
  static TYPE& getInstance()
  {
    Mutex::AutoLock al(sLock);

    if (sInstance == 0)
      sInstance = new TYPE;

    return *sInstance;
  }
};

// static ��� ������ �ݵ�� �ܺο� ���Ǹ� �ؾ� �մϴ�.
template <typename TYPE> Mutex   Singleton<TYPE>::sLock;
template <typename TYPE> TYPE* Singleton<TYPE>::sInstance = 0;

class Cursor : public Singleton<Cursor>
{
private:
  Cursor() {}

  friend class Singleton<Cursor>;
};


int main()
{
  // Cursor c;


  Cursor& c1 = Cursor::getInstance();
  Cursor& c2 = Cursor::getInstance();

  cout << &c1 << endl;
  cout << &c2 << endl;

}