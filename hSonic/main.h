#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <thread>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

extern HANDLE GetSonicHandle(const std::string & szWatchedProcessName, const std::string & szTargetProcessName, DWORD dwDesiredAccess, BOOL bInheritHandle);

