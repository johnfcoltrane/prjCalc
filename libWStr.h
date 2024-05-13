#pragma once
#if 0
static std::string ConvertWstringToUTF8(const std::wstring& src);
static std::wstring ConvertUTF8ToWstring(const std::string& src);
#endif

extern "C" {
size_t str2wstr(wchar_t* q, int n, const char* p);
size_t wstr2str(char* p, int n, const wchar_t* q);
}
