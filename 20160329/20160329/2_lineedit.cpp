// 2_LineEdit - �߿��� ����!
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// GUI ������ LineEdit�� ����� ���ô�.
class LineEdit
{
	string data;
public:
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = getch();
			if (c == 13) // enter
				break;

			if (isdigit(c)) {
				data.push_back(c);
				cout << c;
			}
		}

		cout << endl;
		return data;
	}
};

int main()
{
	LineEdit edit;
	while (1){
		string s = edit.getData();
		cout << "input: " << s << endl;
	}
}