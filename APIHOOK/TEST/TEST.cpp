// TEST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"


int main()
{
	/*
	WCHAR szCurrentDirectory[MAX_PATH];
	DWORD dwCurDirPathLen;
	dwCurDirPathLen = GetCurrentDirectoryW(MAX_PATH, szCurrentDirectory);
	if (dwCurDirPathLen == 0)
	{
		printf("获取当前目录错误。\n");
		return 0;
	}
	OutputDebugStringW(szCurrentDirectory);
	OutputDebugStringW(L"\n");
	*/

	HANDLE hSemaphoreStatus;
	//hSemaphoreStatus = OpenSemaphore(SYNCHRONIZE, FALSE, L"APIHOOK_Monitor_Semaphore_Status");
	hSemaphoreStatus = CreateSemaphore(NULL, 0, 1, L"APIHOOK_Monitor_Semaphore_Status");
	if (!hSemaphoreStatus)
	{
		printf("fuck\n");
		system("PAUSE");
	}
	ReleaseSemaphore(hSemaphoreStatus, 1, NULL);
	CloseHandle(hSemaphoreStatus);
	hSemaphoreStatus = NULL;

    return 0;
}

