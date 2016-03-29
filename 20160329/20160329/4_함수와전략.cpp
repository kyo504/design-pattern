// 4_�Լ��� ����

#include <iostream>
using namespace std;

bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

// ������ �ʴ� ��ü �˰��򿡼� ���ؾ� �ϴ� ��å �ڵ�� �и��Ǿ�� �Ѵ�.
// -> �Ϲ� �Լ������� ���ϴ� ���� �Լ� ����(�Լ� ������)�� �̾� ���� �ȴ�.
void sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; j++)
			//if (x[i] > x[j])
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
}

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	sort(x, 10);

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;
}