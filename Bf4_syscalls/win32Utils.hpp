#pragma once

#include "types.hpp"

extern "C"
{
  BOOL WriteProcessMemory(
    /* [in]  */  HANDLE  hProcess,
    /* [in]  */  LPVOID  lpBaseAddress,
    /* [in]  */  LPCVOID lpBuffer,
    /* [in]  */  SIZE_T  nSize,
    /* [out] */  SIZE_T  *lpNumberOfBytesWritten
  );

  BOOL ReadProcessMemory(
    /* [in]  */  HANDLE  hProcess,
    /* [in]  */  LPCVOID lpBaseAddress,
    /* [out] */  LPVOID  lpBuffer,
    /* [in]  */  SIZE_T  nSize,
    /* [out] */  SIZE_T  *lpNumberOfBytesRead
  );

  void Sleep(
    /* [in] */ DWORD dwMilliseconds
  );

  HWND FindWindowA(
    /* [in, optional] */ LPCSTR lpClassName,
    /* [in, optional] */ LPCSTR lpWindowName
  );

  DWORD GetWindowThreadProcessId(
    /* [in]            */ HWND    hWnd,
    /* [out, optional] */ LPDWORD lpdwProcessId
  );

  HANDLE OpenProcess(
    /* [in] */ DWORD dwDesiredAccess,
    /* [in] */ BOOL  bInheritHandle,
    /* [in] */ DWORD dwProcessId
  );
}
