// 7_�ݺ���4
// C++ STL���� �ݺ��ڸ� ����ϱ� ���ؼ��� �ݵ�� �����ؾ� �մϴ�.

// �ݺ��� ����(interator category)
//  : �ڷᱸ���� ���¿� ���� ���������� �����ϴ� 
//    ������ �����ε��� ���°�
//    �ٸ���.
// 1. �Է� �ݺ���:       =*p, ++
// 2. ��� �ݺ���:       *p=, ++
// 3. ������ �ݺ���:  �����, ++                => slist
// 4. ����� �ݺ���:  �����, ++, --            => list
// 5. �������� �ݺ���: �����, ++, --, +, -, [] => ���ӵ� �޸�


// list<>   - ���� ���� ����Ʈ
// vector<> - �迭                     []

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
  list<int> s;

  s.sort();
  // sort(s.begin(), s.end());
}


#if 0
// List<Integer> s = new LinkedList<>();
// ....
int main()
{
  array<int, 5> v;
  // v.push_back(10);
  // v.push_back(20);
  // v.push_back(30);

  auto p = find(v.begin(), v.end(), 20);
  cout << *p << endl;
}
#endif


#if 0
int main()
{

}
#endif
