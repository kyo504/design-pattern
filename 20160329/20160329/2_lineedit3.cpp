// 2_LineEdit3
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 공통성과 가변성을 분리하는 방법 2.
//	- 변하는 것을 인터페이스 기반 클래스로 분리한다.
//  - Strategy Pattern

// 1. 실행 시간에 정책을 교체하는 것이 가능하다.
// 2. 정책을 재사용하는 것이 가능하다.

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

// GUI 도구인 LineEdit를 만들어 봅시다.
class LineEdit
{
	string data;
	IValidator* pValidator;
public:
	LineEdit() : pValidator(0) {}
	void setValidate(IValidator* p) {
		pValidator = p;
	}

	// 방법 1. 변하는 것은 가상함수화 한다. - "template method 패턴"
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

// 이제 정책을 변경하고 싶다면 파생 클래스에서 가상함수를 재정의 하면 된다.
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