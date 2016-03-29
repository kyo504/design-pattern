#include <iostream>
using namespace std;

// 3_단위전략2

// 단위 전략(Policy-based Design) - "Modern C++ design"
// => 정책을 담은 코드를 컴파일 시간에 생성해 내는 기술
// => C++ 표준 라이브러리의 핵심 디자인 기법

// 장점: 가상함수가 아닌 인라인 함수이다. 호출에 따른 성능 저하가 없다.
// 단점: 정책 클래스가 함수가아닌 템플릿 인자로 전달되므로 실행시에 정책을 교체하는 것이 불가능 한다.
//		=> 컴파일 할 때 정책이 결정된다.!!!

// 상속을 사용한 단위 전략 방식
template <typename T, typename ThreadModel = SingleThread>
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		lock();
		// ...
		unlock();
	}
};

class SingleThread
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class MultiThread
{
public:
	void lock() { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }
};

List<int, MultiThread> st;

int main()
{

	return 0;
}