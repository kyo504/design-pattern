// 3_ĳ����.cpp
#include <iostream>
using namespace std;

// 1. C�� ĳ������ ���̼����̴�. (������ ���� �ְ� �׷��� ���� ���� �ִ�)
// 2. �׷��� C++ �� 4���� ĳ������ ���� �����Ѵ�.
//		- static_cast: void* -> �ٸ� Ÿ�� �Ǵ� ������ �ִ� ĳ���ø� ���
//		- reinterpret_cast: �޸� ���ؼ� (�÷��� ���� �ٸ��� ������ �� �ֱ� ������ �����ؾ� �Ѵ�.)
//		- const_cast: ��ü�� �����, �ֹ߼�(volitile)�� �����ϴ� �뵵�θ� ���
//		- dynamic_cast: RTTI ���, �ٿ� ĳ���� �뵵�� ��� ��

/*
	volitile
	�޸� ���ü��� ���� �ϱ� ���ؼ� �����
*/

int main()
{
	const int c = 10;

	int* p = const_cast<int*>(&c);
	*p = 20;

	cout << *p << endl;
	cout << c << endl;
}

#if 0
int main()
{
	//int *p1 = (int*)malloc(sizeof(100));
	int *p1 = static_cast<int*>(malloc(sizeof(100)));

	int n = 0;
	// double* p = (double*)&n; // c ��Ÿ�Ϸδ� ĳ���� ������ �޸� ħ���� �Ǵ� ������ �߻��� �� �ִ�.
	double* p = reinterpret_cast<double*>(&n);
	*p = 3.14; // ���� �ؾ� �Ѵ�
}
#endif