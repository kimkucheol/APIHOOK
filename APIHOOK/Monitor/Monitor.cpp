// Monitor.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Monitor.h"


int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{

	if (2 != argc) {
		ShowHelp();
	}
	else if (CSTR_EQUAL == CompareString(LOCALE_SYSTEM_DEFAULT, LINGUISTIC_IGNORECASE, argv[1], -1, L"start", -1))
	{
		StartMonitor();
	}
	else if (CSTR_EQUAL == CompareString(LOCALE_SYSTEM_DEFAULT, LINGUISTIC_IGNORECASE, argv[1], -1, L"stop", -1))
	{
		StopMonitor();
	}
	else if (CSTR_EQUAL == CompareString(LOCALE_SYSTEM_DEFAULT, LINGUISTIC_IGNORECASE, argv[1], -1, L"restart", -1))
	{
		RestartMonitor();
	}
	else
	{
		OutputDebugString(L"Tooooooo Many\n");
		ShowHelp();
	}

	system("PAUSE");
    return 0;
}

void ShowHelp()
{
	OutputDebugString(L"Help: Monitor.exe start|stop|restart\n");
	//TODO: showhelp
}

void StartMonitor()
{
	OutputDebugString(L"Do start \n");

	HANDLE hMutexSingleton = NULL;
	HANDLE hSemaphoreStatus = NULL;
	HANDLE hSemaphoreInject = NULL;
	HANDLE hThreadLog = NULL;

	hMutexSingleton = CreateMutex(NULL, TRUE, L"APIHOOK_Monitor_Mutex_Singleton");
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		OutputDebugString(L"ERROR_ALREADY_EXISTS\n");
		printf("ERROR_ALREADY_EXISTS\n");
		ShowHelp();
		return;
	}
	if (!hMutexSingleton)
	{
		OutputDebugString(L"CreateMutex ERROR\n");
		return;
	}
	hSemaphoreStatus = CreateSemaphore(NULL, 0, 1, L"APIHOOK_Monitor_Semaphore_Status");
	if (!hSemaphoreStatus)
	{
		OutputDebugString(L"CreateSemaphore ERROR\n");
		return;
	}
	hSemaphoreInject = CreateSemaphore(NULL, 0, 1, L"APIHOOK_Monitor_Semaphore_Inject");
	if (!hSemaphoreInject)
	{
		OutputDebugString(L"CreateSemaphore ERROR\n");
		return;
	}
	//TODO: create new thread
	
	WaitForSingleObject(hSemaphoreInject, INFINITE);
	//TODO: create new process

	WaitForSingleObject(hThreadLog, INFINITE);
	ReleaseMutex(hMutexSingleton);
	CloseHandle(hMutexSingleton);
	hMutexSingleton = NULL;
	CloseHandle(hSemaphoreStatus);
	hSemaphoreStatus = NULL;
	CloseHandle(hSemaphoreInject);
	hSemaphoreInject = NULL;
}

void StopMonitor()
{
	OutputDebugString(L"Do stop \n");
}

void RestartMonitor()
{
	OutputDebugString(L"Do restart \n");
}