# C++17 Low Cognitive Load and Non-Verbose Spiritual Successor to Boost lexical_cast

In contrast of the template function overloading approach used in Boost lexical_cast, this library uses function overloading.

To reduce the scope only, string conversion to number and vice versa are implemented. Static member functions are listed below for convenience since this is a header only library, so it is diffcult to search for the available functions. For brevity, `static` keyword and `nodiscard` attributes are omitted from the listing below. Exception, if any, is caught within the function and not rethrown.

SF class handles the string to float conversions.

```Cpp
// string convert to float
struct SF
{
  // std::string_view convert to float
  //===================================
  bool conv(string_view str, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(string_view str, double& num, chars_format fmt = general, errc* ec = nullptr);
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
  bool conv(wstring_view wstr, float&  num, chars_format fmt = general, errc* ec = nullptr);
  bool conv(wstring_view wstr, double& num, chars_format fmt = general, errc* ec = nullptr);
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

FS class handles float to string conversion.

```Cpp
// float convert to string
struct FS
{
  // float convert to string
  //===================================
  bool conv(float  num, string& str, chars_format fmt = chars_format::general);
  bool conv(double num, string& str, chars_format fmt = chars_format::general);
  // float convert to char*
  //===================================
  bool conv(float  num, char* str, size_t len, chars_format fmt = general);
  bool conv(double num, char* str, size_t len, chars_format fmt = general);
  // float convert to wstring
  //===================================
  bool conv(float  num, wstring& str, chars_format fmt = chars_format::general);
  bool conv(double num, wstring& str, chars_format fmt = chars_format::general);
  // float convert to wchar_t*
  //===================================
  bool conv(float  num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
  bool conv(double num, wchar_t* wstr, size_t len, chars_format fmt = chars_format::general);
};
```

SN class handles string to number conversion.

```Cpp
// string convert to number
struct SN
{
  // std::string_view convert to number
  //===================================
  bool conv(string_view str, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(string_view str, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(string_view str, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(string_view str, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(string_view str, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(string_view str, uint64_t& num, int base = 10, errc* ec = nullptr);
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
  bool conv(wstring_view wstr, int16_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(wstring_view wstr, uint16_t& num, int base = 10, errc* ec = nullptr);
  bool conv(wstring_view wstr, int32_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(wstring_view wstr, uint32_t& num, int base = 10, errc* ec = nullptr);
  bool conv(wstring_view wstr, int64_t&  num, int base = 10, errc* ec = nullptr);
  bool conv(wstring_view wstr, uint64_t& num, int base = 10, errc* ec = nullptr);
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

NS class handles number to string conversion.

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

You can ignore the naive wide string to string conversion and vice versa. They are used internally by other class.

```Cpp
// string convert to string
struct SS
{
  // wstring convert to string
  //===================================
  bool conv(wstring_view view,   string& str);
  bool conv(const wstring& wstr, string& str);
  bool conv(const wchar_t* wstr, string& str);
  // string convert to wstring
  //===================================
  bool conv(string_view view,  wstring& wstr);
  bool conv(const string& str, wstring& wstr);
  bool conv(const char* str,   wstring& wstr);
};
```
