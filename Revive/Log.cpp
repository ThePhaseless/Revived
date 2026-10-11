#include "Log.h"

#include <Windows.h>
#include <Shlobj.h>
#include <Shlwapi.h>
#include <stdarg.h>
#include <stdio.h>
#include <mutex>

static FILE* OpenLogFile()
{
	// Use the same data folder as ReviveInjector
	wchar_t dataFolder[MAX_PATH] = {};
	DWORD size = sizeof(dataFolder);
	if (RegGetValueW(HKEY_CURRENT_USER, L"Software\\Revived", L"DataFolder", RRF_RT_REG_SZ, NULL, dataFolder, &size) != ERROR_SUCCESS ||
		wcscmp(dataFolder, L"Revived") != 0)
		wcscpy_s(dataFolder, L"Revive");

	wchar_t exePath[MAX_PATH];
	GetModuleFileNameW(NULL, exePath, MAX_PATH);
	PathRemoveExtensionW(exePath);

	wchar_t fileName[MAX_PATH];
	swprintf_s(fileName, L"LibRevive_%s.txt", PathFindFileNameW(exePath));

	wchar_t path[MAX_PATH];
	if (FAILED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, path)) ||
		!PathAppendW(path, dataFolder))
		return nullptr;

	CreateDirectoryW(path, NULL);
	if (!PathAppendW(path, fileName))
		return nullptr;

	return _wfopen(path, L"w");
}

void LogMessage(const char* format, ...)
{
	static std::mutex mutex;
	static FILE* file = OpenLogFile();
	if (!file)
		return;

	std::lock_guard<std::mutex> lock(mutex);

	SYSTEMTIME time;
	GetLocalTime(&time);
	fprintf(file, "%02d:%02d:%02d.%03d ", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_list args;
	va_start(args, format);
	vfprintf(file, format, args);
	va_end(args);

	fputc('\n', file);
	fflush(file);
}
