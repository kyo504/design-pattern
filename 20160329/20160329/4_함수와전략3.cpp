// 3_�Լ�������3
#include <iostream>
using namespace std;

// �Լ� vs �Լ� ��ü
// 1) �Լ��� �ڽŸ��� Ÿ���� ����.
//    �ñ״�ó�� ������ ��� �Լ��� ���� Ÿ���̴�.

// 2) �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//    �ñ״�ó�� �����ϴ��� ��� �Լ� ��ü�� �ٸ� Ÿ���̴�.


// �Լ� ��ü => �Լ�ó�� ��� ������ ��ü
struct Plus
{
	int operator()(int a, int b) {
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(10, 20);
	cout << n << endl;
}