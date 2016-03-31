// 5_ΩÃ±€≈Ê3

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
    Mutex::AutoLock al(sLock);

    if (sInstance == 0)
      sInstance = new Cursor;

    return *sInstance;
  }
};

Mutex   Cursor::sLock;
Cursor* Cursor::sInstance = 0;


int main()
{
  Cursor& c1 = Cursor::getInstance();
  Cursor& c2 = Cursor::getInstance();

  cout << &c1 << endl;
  cout << &c2 << endl;

}