// 1_�߻�Ŭ����

#include <iostream>
using namespace std;

// C++������ ������ �߻� Ŭ������ ����� ������ �������� �ʰ� ���� ���� �Լ��� �̿��Ѵ�.
// �߻� Ŭ����
// ���� : ���� ���� �Լ��� 1�� �̻� �ִ� Ŭ����
// �ǵ� : �Ļ� Ŭ�������� Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��.

class Shape
{
public:
	virtual void draw = 0; // ���� ���� �Լ�
};

// draw�� �����θ� �������� ������ 
// Rect ���� �߻� Ŭ������ �ȴ�.
class Rect : public Shape
{

};

int main()
{
	Shape s;
	Rect r;
}
