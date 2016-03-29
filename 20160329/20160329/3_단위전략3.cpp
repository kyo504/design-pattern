// 3_단위전략3
#include <iostream>
#include <string>
using namespace std;

// 디자인 관점에서...
// API Design on C++

// 언어 관점에서...
// C++ - 스캇 마이어스
// Effective ++
// More Effective C++
// Modern Effective C++
// Effective STL

// 허브 셔터
// Exceptional C++
// More Exceptional C++
// Exceptional C++ Style

// 허브 셔터 & 안드레이 알렉산드르쿠
// C++ Coding Style

// Modern C++ Design

class my_traits : public char_traits < char >
{
	static bool compare(const char* a, const char* b, size_t sz)
	{
		return strcmpi(a, b);
	}
};

// STL 관련 강의
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