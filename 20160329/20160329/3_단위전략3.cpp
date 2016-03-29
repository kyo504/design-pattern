// 3_��������3
#include <iostream>
#include <string>
using namespace std;

// ������ ��������...
// API Design on C++

// ��� ��������...
// C++ - ��ı ���̾
// Effective ++
// More Effective C++
// Modern Effective C++
// Effective STL

// ��� ����
// Exceptional C++
// More Exceptional C++
// Exceptional C++ Style

// ��� ���� & �ȵ巹�� �˷���帣��
// C++ Coding Style

// Modern C++ Design

class my_traits : public char_traits < char >
{
	static bool compare(const char* a, const char* b, size_t sz)
	{
		return strcmpi(a, b);
	}
};

// STL ���� ����
// mr.stl stl lecture Stephan T Lavavej (Microsoft)
// cppcon.org
// - github
// - youtube

// basic_string
typedef basic_string<char, my_traits> mystring;

int main()
{
	string s1 = "abcd";
	string s2 = "ABCD";

	if (s1 == s2)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}