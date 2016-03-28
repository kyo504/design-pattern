// 2_thiscall

#include <iostream>
using namespace std;

class Point
{
	int x, y;

public:
	void set(int a, int b){	// void set(Point* const this, int a, int b)
		x = a;				// this->x = a;
		b = b;				// this->y = b;
	};

	static void foo(int a) {
		x = a;					// this-.
	};
};

int main()
{
	Point::foo(10);
	Point p1;
	p1.set(10, 20);



	return 0;
}

