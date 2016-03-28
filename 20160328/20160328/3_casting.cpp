// 3_캐스팅.cpp
#include <iostream>
using namespace std;

// 1. C의 캐스팅은 비이성적이다. (안전할 떄도 있고 그렇지 않을 때도 있다)
// 2. 그래서 C++ 는 4개의 캐스팅을 새로 제공한다.
//		- static_cast: void* -> 다른 타입 또는 연관성 있는 캐스팅만 허용
//		- reinterpret_cast: 메모리 재해석 (플랫폼 마다 다르게 동작할 수 있기 때문에 주의해야 한다.)
//		- const_cast: 객체의 상수성, 휘발성(volitile)을 제거하는 용도로만 사용
//		- dynamic_cast: RTTI 기술, 다운 캐스팅 용도로 사용 됨

/*
	volitile
	메모리 가시성을 제거 하기 위해서 사용함
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
	// double* p = (double*)&n; // c 스타일로는 캐스팅 되지만 메모리 침범이 되는 문제가 발생할 수 있다.
	double* p = reinterpret_cast<double*>(&n);
	*p = 3.14; // 주의 해야 한다
}
#endif