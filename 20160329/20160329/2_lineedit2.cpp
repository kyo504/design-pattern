// 2_LineEdit - �߿��� ����!
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// template method ������ �Ѱ���
// 1) ���� �ð��� ��å�� ��ü�ϴ� ���� �Ұ����Ѵ�.
//    ��ü�� ������ �ƴ� Ŭ������ ����
// 2) ���ο��� ���Ǵ� ��å�� �ٸ� Ŭ�������� �����ϴ� ���� �Ұ����ϴ�.

// GUI ������ LineEdit�� ����� ���ô�.
class LineEdit
{
	string data;
public:
	// Validation ��å�� ������ �����ؾ� �Ѵ�.
	// - ������ �ʴ� �ڵ�(���뼺)���� ���ؾ� �ϴ� ��(������)�� �ִٸ� 
	//   �и��ؾ� �Ѵ�.

	// ��� 1. ���ϴ� ���� �����Լ�ȭ �Ѵ�. - "template method ����"
	virtual bool validate(char c) { return isdigit(c); }
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = getch();
			if (c == 13) // enter
				break;

			//if (isdigit(c)) {
			if (validate(c))
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

// ���� ��å�� �����ϰ� �ʹٸ� �Ļ� Ŭ�������� �����Լ��� ������ �ϸ� �ȴ�.
class AddressEdit : public LineEdit
{
public:
	virtual bool validatae(char c) { return true; }
};

int main()
{
	LineEdit edit;
	while (1){
		string s = edit.getData();
		cout << "input: " << s << endl;
	}
}