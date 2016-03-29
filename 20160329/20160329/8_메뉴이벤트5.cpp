#include <iostream>
using namespace std;
// 8_�޴��̺�Ʈ5

// �Ϲ� �Լ��� ��� Ŭ������ ��� �Լ��� �����ϴ� ������ �Լ� ������ Ÿ����
// ������.

// 3. A�� B�� ���� ���ؼ��� ������ �θ� �����ؾ� �Ѵ�.
//   => FunctionCommand�� MemberCommand�� ������ �θ� ��������.
struct ICommand
{
  virtual void execute() = 0;
  virtual ~ICommand() {}
};

// 1. �Լ� ������ ������ Ŭ������ ������ ���ô�.
class FunctionCommand : public ICommand
{
  typedef void(*HANDLER)();
  HANDLER handler;
public:
  FunctionCommand(HANDLER h) : handler(h) {}

  void execute() { handler(); }
};

// 2. ��� Ŭ������ ��� �Լ��� �ּҸ� ���� �� �ִ� Ŭ������ �����غ���.
template <typename T>
class MemberCommand : public ICommand
{
  typedef void(T::*HANDLER)();
  HANDLER handler;
  T* object;
public:
  MemberCommand(HANDLER h, T* o) : handler(h), object(o) {}
  void execute() { (object->*handler)();  }
};

class Dialog
{
public:
  void close() { cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

// 4. Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ����ϱ� ������ �׻� ������ ���Դϴ�.
//    �Ͻ��� �߷��� ������ �Լ� ���ø����� ���۸� �����մϴ�.
template <typename T>
MemberCommand<T>* cmd(void (T::*f)(), T* o)
{
  return new MemberCommand<T>(f, o);
}

// 5. ���̺귯�� �ϰ����� ���ؼ� FunctionCommand�� ����� cmd�� �����մϴ�.
FunctionCommand* cmd(void(*f)())
{
  return new FunctionCommand(f);
}

int main()
{
  // ICommand* p = new FunctionCommand(&foo);
  ICommand* p = cmd(&foo);
  p->execute();

  Dialog dialog;
  p = cmd(&Dialog::close, &dialog);
  // p = new MemberCommand<Dialog>(&Dialog::close, &dialog);
  p->execute();
}


#if 0
int main()
{
  Dialog dialog;
  MemberCommand<Dialog> mc(&Dialog::close, &dialog);
  mc.execute();

  FunctionCommand fc(&foo);
  fc.execute();
}
#endif

#if 0
// C++������ �Լ� ���ø��� �Ͻ��� �߷��� ����������, Ŭ���� ���ø���
// �Ͻ��� �߷��� �Ұ����մϴ�.
template<typename T>
void hoo(T a) {}        // �Լ� ���ø� - ����� �߷�, �Ͻ��� �߷�

template <typename T>
class AAA               // Ŭ���� ���ø� - ����� �߷�
{};

int main()
{
  hoo(10); hoo(3.14);
  AAA<int> aaa;  AAA<double> aaa2;
}
#endif



















