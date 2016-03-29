// 4_�Լ�������5
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

#include <iostream>
using namespace std;

#include <algorithm>
#include <functional>

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. ��å���� �Լ��� ����� ��
	// ����: ��å�� ������ ��ü�ص� sort()�� ����� �Ѱ��̴�.
	// ����: ��å�� �ζ��� ġȯ�� �ȵǹǷ� ���� ���ϰ� �ִ�.
	sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int))
	sort(x, x + 10, cmp2); // ���� ������ ���

	// 2. ��å���� �Լ� ��ü�� ����� ��
	// ����: ��å�� �ζ��� ġȯ�ǹǷ� ������ �����Ѵ�.
	// ����: ��å�� ��ȯ�� Ƚ�� ��ŭ�� sort() ���� �ڵ� ����
	less<int> f1; 
	greater<int> f2;
	sort(x, x + 10, f1);	// sort(int*, int*, less<int>)
	sort(x, x + 10, f2);	// sort(int*, int*, greater<int>)

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;

	// ����: �Լ� ��ü�� ���� ����� ���� - �͸��� �Լ� ��ü(Ŭ����)
	// C#: �͸��� ��������Ʈ
	// �ڹ�: �Լ��� �������̽�
	// ObjC: ��� ���α׷���

	// 2008����� �����Ϸ����� �̹� ����
	// - VS 2010, gcc 4.5
	sort(x, x + 10, [](int a, int b) { return abs(a) > abs(b); });
}