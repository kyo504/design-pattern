// 4_함수와전략5
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

#include <iostream>
using namespace std;

#include <algorithm>
#include <functional>

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 1. 정책으로 함수를 사용할 때
	// 장점: 정책을 여러번 교체해도 sort()의 기계어는 한개이다.
	// 단점: 정책이 인라인 치환이 안되므로 성능 저하가 있다.
	sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int))
	sort(x, x + 10, cmp2); // 위의 구현을 사용

	// 2. 정책으로 함수 객체를 사용할 때
	// 장점: 정책이 인라인 치환되므로 빠르게 동작한다.
	// 단점: 정책을 교환한 횟수 만큼의 sort() 기계어 코드 생성
	less<int> f1; 
	greater<int> f2;
	sort(x, x + 10, f1);	// sort(int*, int*, less<int>)
	sort(x, x + 10, f2);	// sort(int*, int*, greater<int>)

	for (int i = 0; i < 10; ++i)
		cout << x[i] << endl;

	// 람다: 함수 객체를 쉽게 만드는 문법 - 익명의 함수 객체(클로져)
	// C#: 익명의 델리게이트
	// 자바: 함수형 인터페이스
	// ObjC: 블록 프로그래밍

	// 2008년부터 컴파일러에서 이미 지원
	// - VS 2010, gcc 4.5
	sort(x, x + 10, [](int a, int b) { return abs(a) > abs(b); });
}