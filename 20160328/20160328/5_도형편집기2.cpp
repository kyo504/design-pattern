#include <iostream>
using namespace std;

#include <vector>

// 8_도형편집기.cpp

// 도형 편집기로 배우는 객체 지향 설계의 개념
// 5. 기능이 추가되어도 (기능 확장에 열려 있고, Open)
//		기존 코드는 수정되면 안된다. (코드 수정에는 닫혀야 한다. Close)
//		한다는 이론 => OCP(개방 폐쇄 원칙)

// 6. 다형성은 OCP를 만족한다. (중요!)
// 7. Prototype Pattern: 기존에 존재하는 객체를 복사해서 새로운 객체를 만드는 패턴
//		- "다형성"을 이용한 객체의 복사
//		java: Cloneable, C#: ICloneable, ObjC: Copyable;
//		java: clone();, C#: Clone();, ObjC: copy();

// 8. "Replace type code with polymorphism"
//		-> 리팩토링 용어 입니다.
// 9. Template Method 패턴
//		-> 변하지 않는 전체 알고리즘은 부모가 비 가상함수로 제공하고
//		   변해야 하는 부분은 가상함수화해서 자식이
//		   변경할 수 있게 하는 디자인 방법.
//		-> NVI(Non Virtual Interface)
// 10. DRY(Do not Rpeat Yourself)
//		-> 코드의 중복은 코드의 유지 보수 비용을 증가시킨다.

class Shape {
public:
	// 변하지 않는 전체 흐름에서 변해야 하는 부분을 찾아서
	// 가상 함수로 분리해야 한다.
	// "공통성과 가변성의 분리 방법"

	// Java : final method - 오버라이딩 금지
	void draw() 
	{ 
		cout << "Mutex lock" << endl;
		drawImpl();
		cout << "Mutex unlock" << endl;
	}
	// 자신의 복사본을 만드는 가상함수가 있으면 좋겠다.
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
			cout << "몇 번째 도형을 복사 할까요 >> ";
			int k;
			cin >> k;

			v.push_back(v[k]->clone());

#if 0
			// v[k] 가 Rect? or Circle? 
			// 그럼 타입을 정의해서 한다? => 이건 좋은 방법이 없음...타입이 새로 생길때마다 코드가 늘어난다
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
