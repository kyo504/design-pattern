// 5_upcasting
#include <iostream>
using namespace std;
#include <vector>

// upcasting: public ��Ӹ� �����ϴ�.
// �ٽ� : A�� B�� ���� �ʹٸ� => ������ �θ� ������!

class Animal {

};

class Dog : public Animal {

};

// ���⼭ ���� �߻��Ѵ� (private > public)
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
