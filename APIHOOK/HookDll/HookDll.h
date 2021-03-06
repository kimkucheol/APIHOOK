#pragma once

#include "FileAPI.h"
#include "ProcessAPI.h"
#include "RegAPI.h"
#include "NetAPI.h"

#ifndef __HOOK_DLL__
#define __HOOK_DLL__


void Prepare();
void DoHook();
void DoUnHook();
void Finish();
FARPROC GetRealApiEntry(LPCWSTR lpModuleName, LPCSTR lpProcName);


#endif // !__HOOK_DLL__