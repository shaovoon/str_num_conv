# C++17 Low Cognitive Load and Non-Verbose Spiritual Successor to Boost lexical_cast

In contrast of the template function overloading approach used in Boost lexical_cast, this library uses function overloading.

To reduce the scope only, string conversion to number and vice versa are implemented. Static member functions are listed below for convenience since this is a header only library, so it is diffcult to search for the available functions. For brevity, `static` keyword and `nodiscard` attributes are omitted from the listing below. Exception, if any, is caught within the function and not rethrown.

SF class handles the string to float conversions.

```Cpp
// string to float
struct SF
{
  // std::string_view to float
  //===================================
  bool to(string_view str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(string_view str, double& num, chars_format fmt = general, errc* ec = nullptr);
  // string to float
  //===================================
  bool to(const string& str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(const string& str, double& num, chars_format fmt = general, errc* ec = nullptr);
  // const char* to float
  //===================================
  bool to(const char* str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(const char* str, double& num, chars_format fmt = general, errc* ec = nullptr);
  // wstring_view to float
  //===================================
  bool to(wstring_view wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(wstring_view wstr, double& num, chars_format fmt = general, errc* ec = nullptr);
  // wstring to float
  //===================================
  bool to(const wstring& wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(const wstring& wstr, double& num, chars_format fmt = general, errc* ec = nullptr);
  // const wchar_t* to float
  //===================================
  bool to(const wchar_t* wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool to(const wchar_t* wstr, double& num, chars_format fmt = general, errc* ec = nullptr);
};
```
FS class handles float to string conversion.

```Cpp
// float to string
struct FS
{
  // float to string
  //===================================
  bool to(float  num, string& str, chars_format fmt = chars_format::general);
  bool to(double num, string& str, chars_format fmt = chars_format::general);
  // float to char*
  //===================================
  bool to(float  num, char* str, size_t len, chars_format fmt = general);
  bool to(double num, char* str, size_t len, chars_format fmt = general);
  // float to wstring
  //===================================
  bool to(float  num, wstring& str, chars_format fmt = chars_format::general);
  bool to(double num, wstring& str, chars_format fmt = chars_format::general);
  // float to wchar_t*
  //===================================
  bool to(float  num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
  bool to(double num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
};
```

SN class handles string to number conversion.

```Cpp
// string to number
struct SN
{
  // std::string_view to number
  //===================================
  bool to(string_view str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(string_view str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(string_view str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(string_view str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(string_view str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(string_view str, uint64_t& num, int base = 10, errc* ec = nullptr);
  // string to number
  //===================================
  bool to(const string& str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const string& str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(const string& str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const string& str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(const string& str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const string& str, uint64_t& num, int base = 10, errc* ec = nullptr);
  // const char* to number
  //===================================
  bool to(const char* str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const char* str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(const char* str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const char* str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(const char* str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const char* str, uint64_t& num, int base = 10, errc* ec = nullptr);
  // wstring_view to number
  //===================================
  bool to(wstring_view wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(wstring_view wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(wstring_view wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(wstring_view wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(wstring_view wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(wstring_view wstr, uint64_t& num, int base = 10, errc* ec = nullptr);
  // wstring to number
  //===================================
  bool to(const wstring& wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wstring& wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(const wstring& wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wstring& wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(const wstring& wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wstring& wstr, uint64_t& num, int base = 10, errc* ec = nullptr);
  // const wchar_t* to number
  //===================================
  bool to(const wchar_t* wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wchar_t* wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool to(const wchar_t* wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wchar_t* wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool to(const wchar_t* wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool to(const wchar_t* wstr, uint64_t& num, int base = 10, errc* ec = nullptr);
};
```

NS class handles number to string conversion.

```Cpp
// number to string
struct NS
{
  // number to string
  //===================================
  bool to(int16_t  num, string& str, int base = 10);
  bool to(uint16_t num, string& str, int base = 10);
  bool to(int32_t  num, string& str, int base = 10);
  bool to(uint32_t num, string& str, int base = 10);
  bool to(int64_t  num, string& str, int base = 10);
  bool to(uint64_t num, string& str, int base = 10);
  // number to char*
  //===================================
  bool to(int16_t  num, char* str, size_t len, int base = 10);
  bool to(uint16_t num, char* str, size_t len, int base = 10);
  bool to(int32_t  num, char* str, size_t len, int base = 10);
  bool to(uint32_t num, char* str, size_t len, int base = 10);
  bool to(int64_t  num, char* str, size_t len, int base = 10);
  bool to(uint64_t num, char* str, size_t len, int base = 10);
  // number to wstring
  //===================================
  bool to(int16_t  num, wstring& str, int base = 10);
  bool to(uint16_t num, wstring& str, int base = 10);
  bool to(int32_t  num, wstring& str, int base = 10);
  bool to(uint32_t num, wstring& str, int base = 10);
  bool to(int64_t  num, wstring& str, int base = 10);
  bool to(uint64_t num, wstring& str, int base = 10);
  // number to wchar_t*
  //===================================
  bool to(int16_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool to(uint16_t num, wchar_t* wstr, size_t len, int base = 10);
  bool to(int32_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool to(uint32_t num, wchar_t* wstr, size_t len, int base = 10);
  bool to(int64_t  num, wchar_t* wstr, size_t len, int base = 10);
  bool to(uint64_t num, wchar_t* wstr, size_t len, int base = 10);
};
```

You can ignore the naive wide string to string conversion and vice versa. They are used internally by other class.

```Cpp
// string to string
struct SS
{
  // wstring to string
  //===================================
  bool to(wstring_view view,   string& str);
  bool to(const wstring& wstr, string& str);
  bool to(const wchar_t* wstr, string& str);
  // string to wstring
  //===================================
  bool to(string_view view,  wstring& wstr);
  bool to(const string& str, wstring& wstr);
  bool to(const char* str,   wstring& wstr);
};
```
