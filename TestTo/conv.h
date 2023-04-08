// The MIT License (MIT)
// C++ 17 String Number Conversion 1.0.0
// Copyright (C) 2023 by Shao Voon Wong (shaovoon@yahoo.com)
//
// http://opensource.org/licenses/MIT

#pragma once

#include <charconv>
#include <cstdint>
#include <string_view>
#include <string>

#ifdef _WIN32
	#define SV_SPRINTF sprintf_s
#else
	#define SV_SPRINTF std::sprintf
#endif

namespace cpp17
{
	struct SS
	{
		// std::wstring convert to std::string
		//===================================
		static [[nodiscard]] bool conv(const std::wstring_view& view, std::string& str) {
			try {
				str.reserve(view.size());
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			for (wchar_t c : view)
				str += (char)c;
			return true;
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::string& str) {
			try {
				str.reserve(wstr.size());
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			for (wchar_t c : wstr)
				str += (char)c;
			return true;
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::string& str) {
			std::size_t len = wcslen(wstr);
			try {
				str.reserve(len);
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			for (size_t i = 0; i < len; ++i)
				str += (char)wstr[i];
			return true;
		}

		// std::string convert to std::wstring
		//===================================
		static [[nodiscard]] bool conv(const std::string_view& view, std::wstring& wstr) {
			try {
				wstr = std::wstring(view.cbegin(), view.cend());
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(const std::string& str, std::wstring& wstr) {
			try {
				wstr = std::wstring(str.cbegin(), str.cend());
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(const char* str, std::wstring& wstr) {
			std::size_t len = strlen(str);
			try {
				wstr = std::wstring(str, str + len);
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
	};
	struct SF
	{
		// std::string_view convert to float
		//===================================
		static [[nodiscard]] bool conv(const std::string_view& str, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			auto ret = std::from_chars(str.data(), str.data() + str.length(), num, fmt);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			auto ret = std::from_chars(str.data(), str.data() + str.length(), num, fmt);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		// std::string convert to float
		//===================================
		static [[nodiscard]] bool conv(const std::string& str, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		// const char* convert to float
		//===================================
		static [[nodiscard]] bool conv(const char* str, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, fmt, ec);
		}
		static [[nodiscard]] bool conv(const char* str, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, fmt, ec);
		}
		// std::wstring_view convert to float
		//===================================
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		// std::wstring convert to float
		//===================================
		static [[nodiscard]] bool conv(const std::wstring& wstr, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		// const wchar_t* convert to float
		//===================================
		static [[nodiscard]] bool conv(const wchar_t* wstr, float& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, double& num, std::chars_format fmt = std::chars_format::general, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, fmt, ec);
		}

	};
	struct FS
	{
		// float convert to std::string
		//===================================
		static [[nodiscard]] bool conv(float num, std::string& str, std::chars_format fmt = std::chars_format::general) {
			try {
				if (fmt == std::chars_format::general || fmt == std::chars_format::fixed)
					str = std::to_string(num);
				else if (fmt == std::chars_format::scientific)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%e", num) < 0)
						return false;
					str = buf;
				}
				else if (fmt == std::chars_format::hex)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%a", num) < 0)
						return false;
					str = buf;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(double num, std::string& str, std::chars_format fmt = std::chars_format::general) {
			try {
				if (fmt == std::chars_format::general || fmt == std::chars_format::fixed)
					str = std::to_string(num);
				else if (fmt == std::chars_format::scientific)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%e", num) < 0)
						return false;
					str = buf;
				}
				else if (fmt == std::chars_format::hex)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%a", num) < 0)
						return false;
					str = buf;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		// float convert to char*
		//===================================
		static [[nodiscard]] bool conv(float num, char* str, size_t len, std::chars_format fmt = std::chars_format::general) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, fmt);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(double num, char* str, size_t len, std::chars_format fmt = std::chars_format::general) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, fmt);
			return ret.ec == std::errc();
		}
		// float convert to std::wstring
		//===================================
		static [[nodiscard]] bool conv(float num, std::wstring& wstr, std::chars_format fmt = std::chars_format::general) {
			try {
				if (fmt == std::chars_format::general || fmt == std::chars_format::fixed)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, fmt))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(double num, std::wstring& wstr, std::chars_format fmt = std::chars_format::general) {
			try {
				if (fmt == std::chars_format::general || fmt == std::chars_format::fixed)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, fmt))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		// float convert to wchar_t*
		//===================================
		static [[nodiscard]] bool conv(float num, wchar_t* wstr, size_t len, std::chars_format fmt = std::chars_format::general) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, fmt))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(double num, wchar_t* wstr, size_t len, std::chars_format fmt = std::chars_format::general) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, fmt))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}

	};
	struct SN
	{
	private:
		static [[nodiscard]] bool Is0x(const std::string_view& str, int base) {
			return (base == 16 && (str.length() > 2 && str[0] == '0' && (str[1] == 'X' || str[1] == 'x')));
		}
	public:
		// std::string_view convert to number
		//===================================
		static [[nodiscard]] bool conv(const std::string_view& str, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(const std::string_view& str, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			size_t offset = Is0x(str, base) ? 2 : 0;
			auto ret = std::from_chars(str.data() + offset, str.data() + str.length(), num, base);
			if (ec) *ec = ret.ec;
			return ret.ec == std::errc();
		}
		// std::string convert to number
		//===================================
		static [[nodiscard]] bool conv(const std::string& str, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::string& str, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		// const char* convert to number
		//===================================
		static [[nodiscard]] bool conv(const char* str, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		static [[nodiscard]] bool conv(const char* str, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		static [[nodiscard]] bool conv(const char* str, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		static [[nodiscard]] bool conv(const char* str, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		static [[nodiscard]] bool conv(const char* str, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		static [[nodiscard]] bool conv(const char* str, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			return conv(std::string_view(str), num, base, ec);
		}
		// std::wstring_view convert to number
		//===================================
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;
			
			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring_view& wstr, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}

		// std::wstring convert to number
		//===================================
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const std::wstring& wstr, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		// const wchar_t* convert to number
		//===================================
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::int16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::uint16_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::int32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::uint32_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::int64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
		static [[nodiscard]] bool conv(const wchar_t* wstr, std::uint64_t& num, int base = 10, std::errc* ec = nullptr) {
			std::string str;
			if (!SS::conv(wstr, str))
				return false;

			return conv(std::string_view(str.c_str(), str.size()), num, base, ec);
		}
	};
	struct NS
	{
	public:
		// number convert to std::string
		//===================================
		static [[nodiscard]] bool conv(std::int16_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string((int)num);
				else if (base == 8)
				{
					const size_t len = 10;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%o", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 10;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%X", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint16_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string((unsigned int)num);
				else if (base == 8)
				{
					const size_t len = 10;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%o", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 10;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%X", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::int32_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string(num);
				else if (base == 8)
				{
					const size_t len = 20;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%o", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 20;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%X", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint32_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string(num);
				else if (base == 8)
				{
					const size_t len = 20;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%o", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 20;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%X", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::int64_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string(num);
				else if (base == 8)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%llo", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%llX", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint64_t num, std::string& str, int base = 10) {
			try {
				if (base == 10)
					str = std::to_string(num);
				else if (base == 8)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%llo", num) < 0)
						return false;
					str = buf;
				}
				else if (base == 16)
				{
					const size_t len = 40;
					char buf[len];
					memset(buf, 0, len * sizeof(char));
					if (SV_SPRINTF(buf, "%llX", num) < 0)
						return false;
					str = buf;
				}
				else
					return false;
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		// number convert to char*
		//===================================
		static [[nodiscard]] bool conv(std::int16_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(std::uint16_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(std::int32_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(std::uint32_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(std::int64_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		static [[nodiscard]] bool conv(std::uint64_t num, char* str, size_t len, int base = 10) {
			memset(str, 0, len * sizeof(char));
			auto ret = std::to_chars(str, str + len - 1, num, base);
			return ret.ec == std::errc();
		}
		// number convert to std::wstring
		//===================================
		static [[nodiscard]] bool conv(std::int16_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring((int)num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint16_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring((unsigned int)num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::int32_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint32_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::int64_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		static [[nodiscard]] bool conv(std::uint64_t num, std::wstring& wstr, int base = 10) {
			try {
				if (base == 10)
					wstr = std::to_wstring(num);
				else
				{
					std::string str;
					if (!conv(num, str, base))
						return false;

					if (!SS::conv(str, wstr))
						return false;
				}
			}
			catch (std::bad_alloc&)
			{
				return false;
			}
			return true;
		}
		// number convert to wchar_t*
		//===================================
		static [[nodiscard]] bool conv(std::int16_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(std::uint16_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(std::int32_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(std::uint32_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(std::int64_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}
		static [[nodiscard]] bool conv(std::uint64_t num, wchar_t* wstr, size_t len, int base = 10) {
			memset(wstr, 0, len * sizeof(wchar_t));
			std::string str;
			str.resize(len);

			if (conv(num, str.data(), len, base))
			{
				for (size_t i = 0; i < len; ++i) {
					if (str[i] == '\0')
						break;

					wstr[i] = str[i];
				}

				return true;
			}
			return false;
		}

	};
}