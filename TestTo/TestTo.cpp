#include <iostream>
#include <cassert>
#include "conv.h"

using namespace cpp17;
using namespace std;

template<typename NumType, typename CharType, int len>
void test_num_to_str(NumType n, const CharType* answer, int base = 10)
{
	std::basic_string<CharType> s;
	assert(NS::conv(n, s, base));
	assert(s == answer);

	CharType buf[len];
	assert(NS::conv(n, buf, len, base));
	assert(s == buf);
}

template<typename NumType, typename CharType, int len>
void test_str_to_num(const CharType* src, NumType answer, int base = 10)
{
	NumType n;
	assert(SN::conv(src, n, base));
	assert(n == answer);

	n = 0;
	std::basic_string<CharType> s = src;
	assert(SN::conv(s, n, base));
	assert(n == answer);

	n = 0;
	std::basic_string_view<CharType> sview(src);
	assert(SN::conv(sview, n, base));
	assert(n == answer);
}

void test_num_to_str_list();
void test_str_to_num_list();

int main()
{
	test_num_to_str_list();
	test_str_to_num_list();

	std::cout << "Tests done." << std::endl;

	return 0;
}

/*
// conv() examples of converting PI to string.
int main()
{
	double pi = 3.14159265359;
	std::string str;
	bool ret1 = FS::conv(pi, str, 7);
	std::cout << "str:" << str << std::endl;

	return 0;
}
*/


/*
// Error handling example
int main()
{
	int num = 0;
	std::errc error;
	std::string student_id = "abc";
	if (!SN::conv(student_id, num, 10, &error))
	{
		if (error == std::errc::invalid_argument)
			std::cerr << "error: student_id is non-numeric:" << student_id << std::endl;
	}
	else
		std::cout << "num:" << num << std::endl;

	return 0;
}
*/

/*
// conv() examples of converting float to string.
int main()
{
	float num = 123.0f;
	std::string str;
	bool ret1 = FS::conv(num, str);
	std::cout << "str:" << str << std::endl;

	return 0;
}
*/

/*
// conv() examples of converting string to float.
int main()
{
	float num = 0;
	std::string str = "123";
	bool ret1 = SF::conv(str, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char* cstr = "123";
	bool ret2 = SF::conv(cstr, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char arr[] = "123";
	bool ret3 = SF::conv(arr, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	std::string_view strv = "123";
	bool ret4 = SF::conv(strv, num);
	std::cout << "num:" << num << std::endl;

	return 0;
}
*/

/*
// conv() examples of converting string to number.
int main()
{
	int num = 0;
	std::string str = "123";
	bool ret1 = SN::conv(str, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char* cstr = "123";
	bool ret2 = SN::conv(cstr, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char arr[] = "123";
	bool ret3 = SN::conv(arr, num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	std::string_view strv = "123";
	bool ret4 = SN::conv(strv, num);
	std::cout << "num:" << num << std::endl;

	return 0;
}
*/

/*
// from_chars() examples
int main()
{
	int num = 0;
	std::string str = "123";
	auto ret1 = std::from_chars(str.data(), str.data() + str.length(), num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char* cstr = "123";
	auto ret2 = std::from_chars(cstr, cstr + strlen(cstr), num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	const char arr[] = "123";
	auto ret3 = std::from_chars(std::begin(arr), std::end(arr), num);
	std::cout << "num:" << num << std::endl;

	num = 0;
	std::string_view strv = "123";
	auto ret4 = std::from_chars(strv.data(), strv.data() + strv.length(), num);
	std::cout << "num:" << num << std::endl;


	return 0;
}
*/

void test_num_to_str_list()
{
	test_num_to_str<int16_t, char, 20>(1234, "1234");
	test_num_to_str<uint16_t, char, 20>(1234, "1234");

	test_num_to_str<int16_t, wchar_t, 20>(1234, L"1234");
	test_num_to_str<uint16_t, wchar_t, 20>(1234, L"1234");

	test_num_to_str<int32_t, char, 40>(12345678, "12345678");
	test_num_to_str<uint32_t, char, 40>(12345678, "12345678");

	test_num_to_str<int32_t, wchar_t, 40>(12345678, L"12345678");
	test_num_to_str<uint32_t, wchar_t, 40>(12345678, L"12345678");

	test_num_to_str<int64_t, char, 40>(1234567890L, "1234567890");
	test_num_to_str<uint64_t, char, 40>(1234567890L, "1234567890");

	test_num_to_str<int64_t, wchar_t, 40>(1234567890L, L"1234567890");
	test_num_to_str<uint64_t, wchar_t, 40>(1234567890L, L"1234567890");

	//////////////////

	test_num_to_str<int16_t, char, 20>(5698, "1642", 16);
	test_num_to_str<uint16_t, char, 20>(5698, "1642", 16);

	test_num_to_str<int16_t, wchar_t, 20>(5698, L"1642", 16);
	test_num_to_str<uint16_t, wchar_t, 20>(5698, L"1642", 16);

	test_num_to_str<int32_t, char, 40>(5698, "1642", 16);
	test_num_to_str<uint32_t, char, 40>(5698, "1642", 16);

	test_num_to_str<int32_t, wchar_t, 40>(5698, L"1642", 16);
	test_num_to_str<uint32_t, wchar_t, 40>(5698, L"1642", 16);

	test_num_to_str<int64_t, char, 40>(5698, "1642", 16);
	test_num_to_str<uint64_t, char, 40>(5698, "1642", 16);

	test_num_to_str<int64_t, wchar_t, 40>(5698, L"1642", 16);
	test_num_to_str<uint64_t, wchar_t, 40>(5698, L"1642", 16);

	//////////////////

	test_num_to_str<int16_t, char, 20>(5698, "13102", 8);
	test_num_to_str<uint16_t, char, 20>(5698, "13102", 8);

	test_num_to_str<int16_t, wchar_t, 20>(5698, L"13102", 8);
	test_num_to_str<uint16_t, wchar_t, 20>(5698, L"13102", 8);

	test_num_to_str<int32_t, char, 40>(5698, "13102", 8);
	test_num_to_str<uint32_t, char, 40>(5698, "13102", 8);

	test_num_to_str<int32_t, wchar_t, 40>(5698, L"13102", 8);
	test_num_to_str<uint32_t, wchar_t, 40>(5698, L"13102", 8);

	test_num_to_str<int64_t, char, 40>(5698, "13102", 8);
	test_num_to_str<uint64_t, char, 40>(5698, "13102", 8);

	test_num_to_str<int64_t, wchar_t, 40>(5698, L"13102", 8);
	test_num_to_str<uint64_t, wchar_t, 40>(5698, L"13102", 8);
}

void test_str_to_num_list()
{
	test_str_to_num<int16_t, char, 20>("1234", 1234);
	test_str_to_num<uint16_t, char, 20>("1234", 1234);

	test_str_to_num<int16_t, wchar_t, 20>(L"1234", 1234);
	test_str_to_num<uint16_t, wchar_t, 20>(L"1234", 1234);

	test_str_to_num<int32_t, char, 40>("12345678", 12345678);
	test_str_to_num<uint32_t, char, 40>("12345678", 12345678);

	test_str_to_num<int32_t, wchar_t, 40>(L"12345678", 12345678);
	test_str_to_num<uint32_t, wchar_t, 40>(L"12345678", 12345678);

	test_str_to_num<int64_t, char, 40>("1234567890", 1234567890L);
	test_str_to_num<uint64_t, char, 40>("1234567890", 1234567890L);

	test_str_to_num<int64_t, wchar_t, 40>(L"1234567890", 1234567890L);
	test_str_to_num<uint64_t, wchar_t, 40>(L"1234567890", 1234567890L);

	//////////////////

	test_str_to_num<int16_t, char, 20>("1642", 5698, 16);
	test_str_to_num<uint16_t, char, 20>("1642", 5698, 16);

	test_str_to_num<int16_t, wchar_t, 20>(L"1642", 5698, 16);
	test_str_to_num<uint16_t, wchar_t, 20>(L"1642", 5698, 16);

	test_str_to_num<int32_t, char, 40>("1642", 5698,  16);
	test_str_to_num<uint32_t, char, 40>("1642", 5698,  16);

	test_str_to_num<int32_t, wchar_t, 40>(L"1642", 5698, 16);
	test_str_to_num<uint32_t, wchar_t, 40>(L"1642", 5698, 16);

	test_str_to_num<int64_t, char, 40>("1642", 5698, 16);
	test_str_to_num<uint64_t, char, 40>("1642", 5698, 16);

	test_str_to_num<int64_t, wchar_t, 40>(L"1642", 5698, 16);
	test_str_to_num<uint64_t, wchar_t, 40>(L"1642", 5698, 16);

	//////////////////

	test_str_to_num<int16_t, char, 20>("0x1642", 5698, 16);
	test_str_to_num<uint16_t, char, 20>("0x1642", 5698, 16);

	test_str_to_num<int16_t, wchar_t, 20>(L"0x1642", 5698, 16);
	test_str_to_num<uint16_t, wchar_t, 20>(L"0x1642", 5698, 16);

	test_str_to_num<int32_t, char, 40>("0x1642", 5698, 16);
	test_str_to_num<uint32_t, char, 40>("0x1642", 5698, 16);

	test_str_to_num<int32_t, wchar_t, 40>(L"0x1642", 5698, 16);
	test_str_to_num<uint32_t, wchar_t, 40>(L"0x1642", 5698, 16);

	test_str_to_num<int64_t, char, 40>("0x1642", 5698, 16);
	test_str_to_num<uint64_t, char, 40>("0x1642", 5698, 16);

	test_str_to_num<int64_t, wchar_t, 40>(L"0x1642", 5698, 16);
	test_str_to_num<uint64_t, wchar_t, 40>(L"0x1642", 5698, 16);

	//////////////////

	test_str_to_num<int16_t, char, 20>("0X1642", 5698, 16);
	test_str_to_num<uint16_t, char, 20>("0X1642", 5698, 16);

	test_str_to_num<int16_t, wchar_t, 20>(L"0X1642", 5698, 16);
	test_str_to_num<uint16_t, wchar_t, 20>(L"0X1642", 5698, 16);

	test_str_to_num<int32_t, char, 40>("0X1642", 5698, 16);
	test_str_to_num<uint32_t, char, 40>("0X1642", 5698, 16);

	test_str_to_num<int32_t, wchar_t, 40>(L"0X1642", 5698, 16);
	test_str_to_num<uint32_t, wchar_t, 40>(L"0X1642", 5698, 16);

	test_str_to_num<int64_t, char, 40>("0X1642", 5698, 16);
	test_str_to_num<uint64_t, char, 40>("0X1642", 5698, 16);

	test_str_to_num<int64_t, wchar_t, 40>(L"0X1642", 5698, 16);
	test_str_to_num<uint64_t, wchar_t, 40>(L"0X1642", 5698, 16);

	//////////////////

	test_str_to_num<int16_t, char, 20>("13102", 5698, 8);
	test_str_to_num<uint16_t, char, 20>("13102", 5698, 8);

	test_str_to_num<int16_t, wchar_t, 20>(L"13102", 5698, 8);
	test_str_to_num<uint16_t, wchar_t, 20>(L"13102", 5698, 8);

	test_str_to_num<int32_t, char, 40>("13102", 5698, 8);
	test_str_to_num<uint32_t, char, 40>("13102", 5698, 8);

	test_str_to_num<int32_t, wchar_t, 40>(L"13102", 5698, 8);
	test_str_to_num<uint32_t, wchar_t, 40>(L"13102", 5698, 8);

	test_str_to_num<int64_t, char, 40>("13102", 5698, 8);
	test_str_to_num<uint64_t, char, 40>("13102", 5698, 8);

	test_str_to_num<int64_t, wchar_t, 40>(L"13102", 5698, 8);
	test_str_to_num<uint64_t, wchar_t, 40>(L"13102", 5698, 8);
}

