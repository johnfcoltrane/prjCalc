#pragma once

static std::string ConvertWstringToUTF8(const std::wstring& src);
static std::wstring ConvertUTF8ToWstring(const std::string& src);

extern "C" {
void str2wstr(wchar_t* q, int n, const char* p);
void wstr2str(char* p, int n, const wchar_t* q);
}
