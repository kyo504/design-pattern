// 5_upcasting
#include <iostream>
using namespace std;
#include <vector>

// upcasting: public 상속만 가능하다.
// 핵심 : A와 B를 묶고 싶다면 => 공통의 부모를 만들어라!

class Animal {

};

class Dog : public Animal {

};

// 여기서 에러 발생한다 (private > public)
class Cat : private Animal {

};

int main()
{
	Dog dog; Cat cat;
	Animal* p = &cat;

	vector<Animal*> animals;

	vector<Dog> dogs;
	vector<Cat> cats;
}
