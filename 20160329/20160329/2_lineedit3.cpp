// 2_LineEdit3
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// ���뼺�� �������� �и��ϴ� ��� 2.
//	- ���ϴ� ���� �������̽� ��� Ŭ������ �и��Ѵ�.
//  - Strategy Pattern

// 1. ���� �ð��� ��å�� ��ü�ϴ� ���� �����ϴ�.
// 2. ��å�� �����ϴ� ���� �����ϴ�.

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool isComplete(string s) { return true; }

	virtual ~IValidator() {}
};

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int v) : value(v) {}

	virtual bool validate(string s, char c)
	{
		return s.size() < value && isdigit(c);
	}

	virtual bool isComplete(string s)
	{
		return s.size() == value;
	}
};

// GUI ������ LineEdit�� ����� ���ô�.
class LineEdit
{
	string data;
	IValidator* pValidator;
public:
	LineEdit() : pValidator(0) {}
	void setValidate(IValidator* p) {
		pValidator = p;
	}

	// ��� 1. ���ϴ� ���� �����Լ�ȭ �Ѵ�. - "template method ����"
	virtual bool validate(char c) { return isdigit(c); }
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = getch();
			if (c == 13 && (pValidator == 0 || pValidator->isComplete(data))) // enter
				break;

			//if (isdigit(c)) {
			if ((pValidator == 0 || pValidator->validate(data, c)) {
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
	LimitDigitValidator v(5);
	edit.setValidate(&v);
	while (1){
		string s = edit.getData();
		cout << "input: " << s << endl;
	}
}