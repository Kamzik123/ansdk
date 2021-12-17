// dllmain.cpp : Defines the entry point for the DLL application.
// Will be updated in a bit
#include "pch.h"
#include "memory.h"
#include <string>
#include <iostream>
#include <process.h>
#include <vector>

// FindDMAAddy - A fucntions to make it easier to handle mulilevel pointers
// Exist on several sites, think original creator can be found here: https://guidedhacking.com/threads/finddmaaddy-c-multilevel-pointer-function.6292/
uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets)
{
  uintptr_t addr = ptr;
  for (unsigned int i = 0; i < offsets.size(); ++i)
  {
    addr = *(uintptr_t*)addr;
    addr += offsets[i];
  }
  return addr;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      _beginthreadex(NULL, 0, &OnLoad, NULL, 0, NULL); // Run in a new thread to not hog the main.
      break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
