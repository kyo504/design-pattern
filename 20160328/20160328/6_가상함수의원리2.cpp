#include <iostream>
using namespace std;
// 6_�����Լ��ǿ���2

class Animal
{
	int age;
public:
	virtual void cry() { cout << "Animal cry" << endl; }
	virtual void foo() {}
	virtual void goo() {}

};

class Dog : public Animal
{
	int color;
public:
	virtual void cry() { cout << "Dog cry" << endl; }
	virtual void foo() {}
};
// http://d.pr/n/16sMV
int main()
{
	Animal a; Dog d;
	cout << sizeof(a) << endl;
	cout << sizeof(d) << endl;


	Animal* p = &d;
	p->cry();       // �� ������ ��Ȯ�� ������ ������ ���ô�.
	// (*p)[0](p);
}