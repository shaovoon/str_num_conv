# C++17 Easy String to Number and Vice Versa

In contrast to the template function overloading approach used in Boost `lexical_cast`, this library uses function overloading. All the functions are named `conv()` to reduce cognitive load to focus on the business logic and reduce mistakes.

To limit the library scope, only string to number conversion and vice versa are implemented. All functions are listed at the bottom for your convenience since this is a header only library, so it can be diffcult to search. For brevity, `static` keyword is omitted.

## Problem Space

There are so many different ways of converting string-to-number and number to string in C++ that developers have to google for this information. For example, to convert a string to an integer, we have 5 functions: [atoi](https://en.cppreference.com/w/cpp/string/byte/atoi), [stoi](https://en.cppreference.com/w/cpp/string/basic_string/stol), [strtol](https://en.cppreference.com/w/cpp/string/byte/strtol), [sscanf](https://en.cppreference.com/w/cpp/io/c/fscanf) and [from_chars](https://en.cppreference.com/w/cpp/utility/from_chars). This library makes use of C++17's `from_chars()` for string-to-number conversion and `to_chars()`/`to_string()` for base 10 number to `char` array/`std::string` conversions. In the case of base 8 and 16, it uses `sprintf()/sprintf_s()`.

To use C++17's `from_chars()`, C++ developers are required to remember 4 different ways depending the source string is a `std::string`, `char` pointer, `char` array or `std::string_view` (See below). And `from_chars()` does not support wide string and this library fills up this gap.

```Cpp
int num = 0;
std::string str = "123";
auto ret1 = std::from_chars(str.data(), str.data() + str.length(), num);

num = 0;
const char* cstr = "123";
auto ret2 = std::from_chars(cstr, cstr + strlen(cstr), num);

num = 0;
const char arr[] = "123";
auto ret3 = std::from_chars(std::begin(arr), std::end(arr), num);

num = 0;
std::string_view strv = "123";
auto ret4 = std::from_chars(strv.data(), strv.data() + strv.length(), num);
```

![Jackie Chan confused by so many ways of using from_chars](img/jackie_chan.jpg)

In comparison, the user of `conv()` supplies two parameters and other parameters such as number base and error are optional. `conv()` was originally named `to()`, it was renamed to avoid a name clash with a function from Range-v3. For base 16, `conv()` ignores "0x" or "0X" prefixes as a convenience while those prefixes are not recognized in `from_chars()`.

```Cpp
bool conv([type] src, [type] dest, ...);
```

These are the `conv` equivalent usages of the above `from_chars` examples.

```Cpp
#include "conv.h"

using namespace cpp17;

int num = 0;
std::string str = "123";
bool ret1 = SN::conv(str,  num);

num = 0;
const char* cstr = "123";
bool ret2 = SN::conv(cstr, num);

num = 0;
const char arr[] = "123";
bool ret3 = SN::conv(arr,  num); // Note: array decay to a pointer.

num = 0;
std::string_view strv = "123";
bool ret4 = SN::conv(strv, num);
```

## Class Names

Initially, all the overloaded functions are inside one class but Visual C++ is overwhelmed by 90 `conv()` overloads, so I divided them up into classes.

* `SF` : Convert string to float
* `SN` : Convert string to number
* `FS` : Convert float to string
* `NS` : Convert number to string
* `SS` : Convert narrow string to wide string and vice versa (For internal use, please ignore)

## Common Compilation Errors

If you get "no overloaded function could convert all the argument types" error, ensure you use the correct class shown above.

If you get `to_chars` and `from_chars` undefined errors, make sure you have C++ Language Standard set to C++17.

![Visual C++ Language Standard set to C++17](img/vc_cpp17.png)

## Error Handling Rationale from Lessons of lexical_cast()

```Cpp
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
```

`conv()` does not throw exception but returns `false` for failure. Developer can supply an `errc` argument for information. In the special case of number to string, there is no error parameter because no failure is possible except for out of memory so caller can safely assume the error is OOM. For some case, it is enough to know the presence of error, not the cause. Sometimes, error is to be expected for optional field not supplied or mutually-excluded fields, say, in a file configuration settings. It is only possible to obtain contextual information at the call site for meaningful error handling. Boost `lexical_cast()` throws exception with a generic error message of "bad lexical cast: source type value could not be interpreted as target". For instance, I put a bunch of `lexical_cast()` calls under a try-catch block, it is not clear to me which conversion failed during exception. This is the sole reason why such [lexical_cast wrapper](https://www.codeproject.com/Articles/1169069/Boost-Lexical-Cast-Wrapper) exists.

## Future Direction

Future plan includes the numeric precision for float-to-string conversion. If this library proves to be popular enough among C++ developers, I intend to do a port to the C++ standard earlier than C++17. Maybe a C++23 [std::expected](https://en.cppreference.com/w/cpp/utility/expected) version is in the cards?

## Catalogue of Overloaded conv()

This section lists all the `conv()` for your convenience since it could be hard to find relevant one in the single header library.

`SF` class handles the string-to-float conversions.

```Cpp
// string convert to float
struct SF
{
  // std::string_view convert to float
  //===================================
  bool conv(const string_view& str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const string_view& str, double& num, chars_format fmt = general, errc* ec = nullptr);

  // string convert to float
  //===================================
  bool conv(const string& str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const string& str, double& num, chars_format fmt = general, errc* ec = nullptr);

  // const char* convert to float
  //===================================
  bool conv(const char* str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const char* str, double& num, chars_format fmt = general, errc* ec = nullptr);

  // wstring_view convert to float
  //===================================
  bool conv(const wstring_view& wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, double& num, chars_format fmt = general, errc* ec = nullptr);

  // wstring convert to float
  //===================================
  bool conv(const wstring& wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const wstring& wstr, double& num, chars_format fmt = general, errc* ec = nullptr);

  // const wchar_t* convert to float
  //===================================
  bool conv(const wchar_t* wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, double& num, chars_format fmt = general, errc* ec = nullptr);
};
```

`FS` class handles float-to-string conversion.

```Cpp
// float convert to string
struct FS
{
  // float convert to string
  //===================================
  bool conv(float  num, string& str, chars_format fmt = chars_format::general);
  bool conv(double num, string& str, chars_format fmt = chars_format::general);

  bool conv(float  num, string& str, int precision);
  bool conv(double num, string& str, int precision);

  // float convert to char*
  //===================================
  bool conv(float  num, char* str, size_t len, chars_format fmt = general);
  bool conv(double num, char* str, size_t len, chars_format fmt = general);

  // float convert to wstring
  //===================================
  bool conv(float  num, wstring& str, chars_format fmt = chars_format::general);
  bool conv(double num, wstring& str, chars_format fmt = chars_format::general);

  bool conv(float  num, wstring& str, int precision);
  bool conv(double num, wstring& str, int precision);

  // float convert to wchar_t*
  //===================================
  bool conv(float  num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
  bool conv(double num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
};
```

`SN` class handles string-to-number conversion.

```Cpp
// string convert to number
struct SN
{
  // std::string_view convert to number
  //===================================
  bool conv(const string_view& str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string_view& str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const string_view& str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string_view& str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const string_view& str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string_view& str, uint64_t& num, int base = 10, errc* ec = nullptr);

  // string convert to number
  //===================================
  bool conv(const string& str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string& str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const string& str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string& str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const string& str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const string& str, uint64_t& num, int base = 10, errc* ec = nullptr);

  // const char* convert to number
  //===================================
  bool conv(const char* str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const char* str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const char* str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const char* str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const char* str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const char* str, uint64_t& num, int base = 10, errc* ec = nullptr);

  // wstring_view convert to number
  //===================================
  bool conv(const wstring_view& wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring_view& wstr, uint64_t& num, int base = 10, errc* ec = nullptr);

  // wstring convert to number
  //===================================
  bool conv(const wstring& wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring& wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring& wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring& wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring& wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wstring& wstr, uint64_t& num, int base = 10, errc* ec = nullptr);

  // const wchar_t* convert to number
  //===================================
  bool conv(const wchar_t* wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(const wchar_t* wstr, uint64_t& num, int base = 10, errc* ec = nullptr);
};
```

`NS` class handles number-to-string conversion.

```Cpp
// number convert to string
struct NS
{
  // number convert to string
  //===================================
  bool conv(int16_t  num, string& str, int base = 10);
  bool conv(uint16_t num, string& str, int base = 10);
  bool conv(int32_t  num, string& str, int base = 10);
  bool conv(uint32_t num, string& str, int base = 10);
  bool conv(int64_t  num, string& str, int base = 10);
  bool conv(uint64_t num, string& str, int base = 10);

  // number convert to char*
  //===================================
  bool conv(int16_t  num, char* str, size_t len, int base = 10);
  bool conv(uint16_t num, char* str, size_t len, int base = 10);
  bool conv(int32_t  num, char* str, size_t len, int base = 10);
  bool conv(uint32_t num, char* str, size_t len, int base = 10);
  bool conv(int64_t  num, char* str, size_t len, int base = 10);
  bool conv(uint64_t num, char* str, size_t len, int base = 10);

  // number convert to wstring
  //===================================
  bool conv(int16_t  num, wstring& str, int base = 10);
  bool conv(uint16_t num, wstring& str, int base = 10);
  bool conv(int32_t  num, wstring& str, int base = 10);
  bool conv(uint32_t num, wstring& str, int base = 10);
  bool conv(int64_t  num, wstring& str, int base = 10);
  bool conv(uint64_t num, wstring& str, int base = 10);

  // number convert to wchar_t*
  //===================================
  bool conv(int16_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool conv(uint16_t num, wchar_t* wstr, size_t len, int base = 10);
  bool conv(int32_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool conv(uint32_t num, wchar_t* wstr, size_t len, int base = 10);
  bool conv(int64_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool conv(uint64_t num, wchar_t* wstr, size_t len, int base = 10);
};
```

You can ignore the `SS` class for naive wide string to narrow string conversion and vice versa. They are used internally by above classes.

```Cpp
// string convert to string
struct SS
{
  // wstring convert to string
  //===================================
  bool conv(const wstring_view& view,   string& str);
  bool conv(const wstring& wstr, string& str);
  bool conv(const wchar_t* wstr, string& str);

  // string convert to wstring
  //===================================
  bool conv(const string_view& view,  wstring& wstr);
  bool conv(const string& str, wstring& wstr);
  bool conv(const char* str,   wstring& wstr);
};
```
