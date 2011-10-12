/*
Copyright (C) 2004 Jacquelin POTIER <jacquelin.potier@free.fr>
Dynamic aspect ratio code Copyright (C) 2004 Jacquelin POTIER <jacquelin.potier@free.fr>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

//-----------------------------------------------------------------------------
// Object: class helper for reading or writing process memory
//-----------------------------------------------------------------------------

#pragma once

#include <windows.h>
#include <stdio.h>
#pragma warning (push)
#pragma warning(disable : 4005)// for '_stprintf' : macro redefinition in tchar.h
#include <TCHAR.h>
#pragma warning (pop)
#include "../../APIError/ApiError.h"

class CProcessMemory
{
private:
    DWORD dwProcessID;
    DWORD dwDesiredAccess;
    HANDLE hProcess;
    BOOL bShowErrorMessage;
    void CommonConstructor(DWORD dwProcessID,BOOL bReadOnly,BOOL bShowErrorMessage);
public:
    CProcessMemory(DWORD dwProcessID,BOOL bReadOnly);
    CProcessMemory(DWORD dwProcessID,BOOL bReadOnly,BOOL bShowErrorMessage);
    ~CProcessMemory(void);
    BOOL Read(LPCVOID lpBaseAddress,LPVOID lpBuffer,SIZE_T nSize,SIZE_T* lpNumberOfBytesRead);
    BOOL Write(LPVOID lpBaseAddress,LPCVOID lpBuffer,SIZE_T nSize,SIZE_T* lpNumberOfBytesWritten);
    BOOL Protect(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
    DWORD Query(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T Length);
    BOOL IsValidMemory(LPCVOID lpAddress,SIZE_T Length);

    BOOL Free(LPVOID lpAddress);
    LPVOID Alloc(SIZE_T dwSize);
    HANDLE GetProcessHandle();
};