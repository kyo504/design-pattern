// 1_�߻�Ŭ����2
#include <iostream>
using namespace std;

// ���� ����: ��ü�� �Ұ����� ������ ������ ���� ���
// �ᱹ �������̽��� ����� ������ ������ ������ ����� �����̴�!!

// 1. ī�޶� ����ڿ� ī�޶� ������ ������ ��Ģ�� ���� ��������.
//		- �������̽�, ��༭, ��������
// C++���� �������̽��� ����� ���
struct ICamera
{
	// defualt method
	virtual void save() {}
	virtual void take() = 0;
	virtual ~ICamera() {}	// �������̽��� �ᱹ �θ��̴�.
							// �ݵ�� ���� �Ҹ��ڰ� �ʿ��ϴ�.
};

// 2. ����ڴ� ��¥ ī�޶�� ������ ��Ģ�� �ִ�. ��Ģ��θ� ����ϸ� �ȴ�.
class Person
{
public:
	void takePicture(ICamera* p)
	{
		p->take();
	}
};

// 3. ī�޶��� �����ڴ� �������̽��� ��ӵ� �Լ��� �����ϴ� ������ ��ü Ŭ������ ����� �ȴ�.
//
// ��Ģ: ��� ī�޶�� ICamera�κ��� �Ļ��Ǿ�� �Ѵ�. ��� ���� ����
//		��� ī�޶�� ICamera�� �����ؾ� �Ѵ�. ��� ǥ���Ѵ�.
class Camera : public ICamera
{
public:
	virtual void take()
	{
		cout << "take picture with Camera" << endl;
	}
};

// 4. ������ ����: Ŭ���̾�Ʈ�� ��ü Ŭ������ �����ϴ� ���� �ƴ϶�
//					�߻� Ŭ������ �������̽��� �����ϴ� ������ ���� ���
//					DIP(Dependency Inversion Principle)
//					=> ����ڴ� �������̽��� �����ϴ� ��ü Ŭ������ ��ü�� �� �ִ�.
//					=> ��ü ������ ������ ������
//					=> OCP�� �����Ѵ�.
class SmartPhone : public ICamera
{
public:
	virtual void take()
	{
		cout << "take picture with SmartPhone" << endl;
	}
};

int main()
{
	Camera c;
	Person p;


}

#if 0
class SmartPhone
{
public:
	void take() { cout << "take picture with SmartPhone" << endl; }
};

class Camera
{
public:
	void take() { cout << "take picture with Camera" << endl; }
};

class Person
{
public:
	void takePicture(Camera* p)
	{
		p->take();
	}
};

int main()
{
	Camera camera;
	Person person;

	person.takePicture(&camera);
}
#endif