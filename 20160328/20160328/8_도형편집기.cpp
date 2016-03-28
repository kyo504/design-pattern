#include <iostream>
using namespace std;

#include <vector>

// 8_����������.cpp

// ���� ������� ���� ��ü ���� ������ ����
// 1. ��� ������ Ÿ��ȭ �ϸ� ���ϴ�.
// 2. ��� ������ ������ �θ� �ִٸ�, ��� ������ ��� ������ �� �ִ�.
// 3. ��� �ڽ��� ����� Ư¡�� �ִٸ� �ݵ�� �θ𿡵� �־�� �Ѵ�.
//		�׷��� �θ� �����ͷ� ��� ����� �� �ش� Ư¡�� �̿��� �� �ִ�.
//		- LSP(Liskov Substitution Principle)
// 4. �θ��� �Լ� �� �ڽ��� �������ϴ� ��� �Լ��� �ݵ�� ���� �Լ� �̾�� �Ѵ�.
//		"���� �Լ��� �ƴ� �Լ��� ���������� ���� ! - Effective C++" �ݾ�

class Shape {
public:
	virtual void draw() { cout << "Shape draw" << endl; }
};

class Rect : public Shape
{
public:
	virtual void draw() { cout << "Rect draw" << endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { cout << "Circle draw" << endl; }
};

int main()
{
	vector<Shape*> v;
	
	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9) {
			for (int i = 0; i < v.size(); ++i)
				v[i]->draw();
		}
	}
}
