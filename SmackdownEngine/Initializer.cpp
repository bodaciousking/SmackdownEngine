#include "stdafx.h"
#include "Initializer.h"

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <direct.h>


using namespace std;
typedef ULONGLONG DWORDLONG, *PDWORDLONG;
#define DIV 1024
#define WIDTH 7

bool Initializer::CheckInstances()
{
	HANDLE Mutex = CreateMutex
	(
		(LPSECURITY_ATTRIBUTES)NULL,
		(BOOL)TRUE,
		(LPCTSTR)"MY_APPLICATION"
	);

	DWORD Error = GetLastError();
	if (Error == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(Mutex);
		Mutex = NULL;

		cout << "ERROR: Program already running" << endl;
		return false;
	}
	else
	{
		cout << "This is the only instance of this program." << endl;
	}
	return true;
}

bool Initializer::CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		cout << "Not enough disk space." << endl;
		return false;
	}
	return true;
}

DWORD Initializer::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"), 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey, _T("~MHz"), NULL, &type, (LPBYTE)& dwMHz, &BufSize);
	}

	cout << "CPU Speed: " << dwMHz << "MHz" << endl;
	return dwMHz;
}

int Initializer::MemoryCheck()
{
	cout << "Hello World!\n";

	MEMORYSTATUSEX myMem;
	myMem.dwLength = sizeof(myMem);

	GlobalMemoryStatusEx(&myMem);

	_tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
		WIDTH, myMem.dwMemoryLoad);
	_tprintf(TEXT("There are %*I64d total KB of physical memory.\n"),
		WIDTH, myMem.ullTotalPhys / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of physical memory.\n"),
		WIDTH, myMem.ullAvailPhys / DIV);
	_tprintf(TEXT("There are %*I64d total KB of paging file.\n"),
		WIDTH, myMem.ullTotalPageFile / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of paging file.\n"),
		WIDTH, myMem.ullAvailPageFile / DIV);
	_tprintf(TEXT("There are %*I64d total KB of virtual memory.\n"),
		WIDTH, myMem.ullTotalVirtual / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of virtual memory.\n"),
		WIDTH, myMem.ullAvailVirtual / DIV);

	// Show the amount of extended memory available.

	_tprintf(TEXT("There are %*I64d free  KB of extended memory.\n"),
		WIDTH, myMem.ullAvailExtendedVirtual / DIV);

	return 0;
}


Initializer::~Initializer()
{
}


Initializer::Initializer()
{
}
