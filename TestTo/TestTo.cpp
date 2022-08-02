// TestTo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include "to.h"

using namespace cpp17;
using namespace std;

template<typename NumType, typename CharType, int len>
void test_num_to_str(NumType n, const CharType* answer, int base = 10)
{
	std::basic_string<CharType> s;
	assert(NS::to(n, s, base));
	assert(s == answer);

	CharType buf[len];
	assert(NS::to(n, buf, len, base));
	assert(s == buf);
}

template<typename NumType, typename CharType, int len>
void test_str_to_num(const CharType* src, NumType answer, int base = 10)
{
	NumType n;
	assert(SN::to(src, n, base));
	assert(n == answer);

	n = 0;
	std::basic_string<CharType> s = src;
	assert(SN::to(s, n, base));
	assert(n == answer);

	n = 0;
	std::basic_string_view<CharType> sview(src);
	assert(SN::to(sview, n, base));
	assert(n == answer);
}

void test_num_to_str_list();
void test_str_to_num_list();

int main()
{
	test_num_to_str_list();
	test_str_to_num_list();
	return 0;
}

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

