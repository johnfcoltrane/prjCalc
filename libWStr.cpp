#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

static std::string ConvertWstringToUTF8(const std::wstring& src)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t> > converter;
	return converter.to_bytes(src);
}

static std::wstring ConvertUTF8ToWstring(const std::string& src)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(src);
}

extern "C"
void str2wstr(wchar_t* q, int n, const char* p) 
{
	std::string src(p);
	std::wstring wstr = ConvertUTF8ToWstring(src);
	const wchar_t* qq = wstr.c_str();
	wcscpy_s(q, n, qq);
}

extern "C"
void wstr2str(char* p, int n, const wchar_t* q) 
{
	std::wstring src(q);
	std::string str = ConvertWstringToUTF8(src);
	const char* qq = str.c_str();
	strcpy_s(p, n, qq);
}
