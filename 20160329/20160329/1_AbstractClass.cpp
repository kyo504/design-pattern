// 1_추상클래스

#include <iostream>
using namespace std;

// C++에서는 별도로 추상 클래스를 만드는 문법을 제공하지 않고 순수 가상 함수를 이용한다.
// 추상 클래스
// 정의 : 순수 가상 함수가 1개 이상 있는 클래스
// 의도 : 파생 클래스에게 특정 함수를 반드시 만들라고 지시하는 것.

class Shape
{
public:
	virtual void draw = 0; // 순수 가상 함수
};

// draw의 구현부를 제공하지 않으면 
// Rect 역시 추상 클래스가 된다.
class Rect : public Shape
{

};

int main()
{
	Shape s;
	Rect r;
}
