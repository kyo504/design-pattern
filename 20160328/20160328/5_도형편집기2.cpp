#include <iostream>
using namespace std;

#include <vector>

// 8_����������.cpp

// ���� ������� ���� ��ü ���� ������ ����
// 5. ����� �߰��Ǿ (��� Ȯ�忡 ���� �ְ�, Open)
//		���� �ڵ�� �����Ǹ� �ȵȴ�. (�ڵ� �������� ������ �Ѵ�. Close)
//		�Ѵٴ� �̷� => OCP(���� ��� ��Ģ)

// 6. �������� OCP�� �����Ѵ�. (�߿�!)
// 7. Prototype Pattern: ������ �����ϴ� ��ü�� �����ؼ� ���ο� ��ü�� ����� ����
//		- "������"�� �̿��� ��ü�� ����
//		java: Cloneable, C#: ICloneable, ObjC: Copyable;
//		java: clone();, C#: Clone();, ObjC: copy();

// 8. "Replace type code with polymorphism"
//		-> �����丵 ��� �Դϴ�.
// 9. Template Method ����
//		-> ������ �ʴ� ��ü �˰����� �θ� �� �����Լ��� �����ϰ�
//		   ���ؾ� �ϴ� �κ��� �����Լ�ȭ�ؼ� �ڽ���
//		   ������ �� �ְ� �ϴ� ������ ���.
//		-> NVI(Non Virtual Interface)
// 10. DRY(Do not Rpeat Yourself)
//		-> �ڵ��� �ߺ��� �ڵ��� ���� ���� ����� ������Ų��.

class Shape {
public:
	// ������ �ʴ� ��ü �帧���� ���ؾ� �ϴ� �κ��� ã�Ƽ�
	// ���� �Լ��� �и��ؾ� �Ѵ�.
	// "���뼺�� �������� �и� ���"

	// Java : final method - �������̵� ����
	void draw() 
	{ 
		cout << "Mutex lock" << endl;
		drawImpl();
		cout << "Mutex unlock" << endl;
	}
	// �ڽ��� ���纻�� ����� �����Լ��� ������ ���ڴ�.
	virtual Shape* clone() { return new Shape(*this); }

protected:
	virtual void drawImpl() {
		cout << "Shape draw" << endl;
	}
};

class Rect : public Shape
{
public:
	virtual Shape* clone() { return new Rect(*this); }

protected:
	virtual void drawImpl() { cout << "Rect draw" << endl; }
};

class Circle : public Shape
{
public:
	virtual Shape* clone() { return new Circle(*this); }

protected:
	virtual void drawImpl() { cout << "Circle draw" << endl; }
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
		else if (cmd == 8) {
			cout << "�� ��° ������ ���� �ұ�� >> ";
			int k;
			cin >> k;

			v.push_back(v[k]->clone());

#if 0
			// v[k] �� Rect? or Circle? 
			// �׷� Ÿ���� �����ؼ� �Ѵ�? => �̰� ���� ����� ����...Ÿ���� ���� ���涧���� �ڵ尡 �þ��
			switch (v[k]->type){
			case 1: // Rect
			case 2: // Circle
			}
#endif
		}
		else if (cmd == 9) {
			for (int i = 0; i < v.size(); ++i)
				v[i]->draw();
		}
	}
}
