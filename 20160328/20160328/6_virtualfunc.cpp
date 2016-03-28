// 6_가상 함수의 원리

#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal
{
public:
	void cry() { cout << "Dog cry" << endl; }
};

int main()
{
	Animal a;
	a.cry();
	Dog d;
	d.cry();

	Animal* p = &d;

}

// 함수 바인딩
// p->cry() 를 어떤 함수로 연결할 것인가?

// 1. static binding:	컴파일 시간에 컴파일러가 결정한다.
//						p의 포인터 타입으로만 결정된다.
// C, C++ 는 정적 바인딩, 빠르다, 비이성적(객체를 담고 있는 포인터의 타입에 따라서 처리된다)

// 2. dynamic binding:	컴파일 시간에는 p의 메모리를 조사하는 기계어 코드 생성
//						실행시간에는 메모리 조사 후 호출
// Java, Objective-C 는 동적 바인딩, 상대적으로 느리다. 이성적이다(객체의 타입에 따라서 처리된다)

// virtual 키워드는 정적 바인딩을 동적 바인딩으로 바꿔줄 수 있다.