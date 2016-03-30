#include <iostream>
using namespace std;

// �Ϲ��� ���α׷���
// C++ ���̺귯���� �����ϱ� ���ؼ��� �Ϲ�ȭ�� ���� �ؾ� �մϴ�.
// C++ - OOP + �Ϲ�ȭ(Generic)

// C�� ���ڿ� �Լ�
char* xstrchr(char *s, char c)
{
  while (*s != '\0' && *s != c)
    ++s;

  return *s == c ? s : NULL;
}

// 1. �˻� ������ �Ϲ�ȭ : �κ� ���ڿ� �˻� �����ϰ� ����.
// [first, last) - �ݰ� ����
char* xstrchr(char* first, char* last, char value)
{
  while (first != last && *first != value)
    ++first;

  return first;
}

// 2. �˻� ��� Ÿ���� �Ϲ�ȭ - template ����
// ������ 1)
// - ������ Ÿ�԰� ã�� ����� Ÿ���� �����Ǿ� �ִ�.
// template <typename T>
// T* xfind(T* first, T* last, T value)

// ������ 2)
//  - T* ��� �ϸ� ��¥ �����͸� ����� �� �ִ�. 
//    ����Ʈ �����͸� ����� �� ����.
template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
  while (first != last && *first != value)
    ++first;

  return first;
}

#include <vector>
#include <algorithm>  // find

int main()
{
  int x[] = { 1, 2, 3 };
  cout << *xfind(x, x + 3, 3) << endl;

  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  cout << *xfind(v.begin(), v.end(), 30) << endl;
}


#if 0
int main()
{
  int x[] = { 1, 2, 3, 4, 5 };
  int* p = xfind(x, x + 5, 3.0);
  if (p != x + 5)
    cout << *p << endl;
}
#endif


#if 0
int main()
{
  char s[] = "abcdefg";
  char* p = xfind(s + 3, s + 7, 'c');
  if (p != s + 7)
    cout << *p << endl;
}
#endif



#if 0
int main()
{
  char s[] = "abcdefg";
  char* p = xstrchr(s, 'c');
  if (p != NULL)
    cout << *p << endl;
}
#endif
