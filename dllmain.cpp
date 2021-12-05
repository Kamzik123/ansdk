// Created by Lambda
// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include "memory.h"
#include <string>
#include <iostream>
#include <vector>

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
