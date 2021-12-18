// dllmain.cpp : Defines the entry point for the DLL application.
// Will be updated in a bit
#include "pch.h"
#include "memory.h"
#include <string>
#include <iostream>
#include <process.h>
#include <vector>


// Create Hooks Should not be here...
bool CreateHooks() {
if(
  MH_CreateHook((PVOID*)memory::find_signature(0, SetPlayerHealthPattern), &SetPlayerHealthOverride, reinterpret_cast<void**>(&ansdk::oSet_Player_Health)) &&
  MH_CreateHook((PVOID*)memory::find_signature(0, Offsets::ShipHealth[0], Offsets::ShipHealth[1]), &ShipHealthOverride, reinterpret_cast<void**>(&ansdk::oship_health))
  != MH_OK) {
  std::cout << "ERROR: One or more hooks could not be created." << std::endl;
    return false;
  }
  std::cout << "All hooks created succesfully." << std::endl;
return true;
}


// Update Function, be careful not tied to game frames.
unsigned int __stdcall Update(void* data) {
#ifdef _DEBUG
  // Holds the input
  std::string input;
#endif  // DEBUG
  // Our loop
  while (true) {
#ifdef _DEBUG
    std::cout << std::endl << "Enter a command, use help or ? to see the list of commands." << std::endl;
    std::cin >> input;

    // Help command just print out the commands we added. Note extremly ugly implementation.

      if (input.find("help") != std::string::npos) 
      {
        std::cout << std::endl << std::endl << "# Commands" << std::endl << std::endl << std::endl;
        std::cout << "Exit : Exit the game without saving" << std::endl;
        std::cout << "GetPlayerHealth : Returns the player health" << std::endl;
        std::cout << "GetWeaponNameFromId : Returns the name of the weapon with the id" << std::endl;
        std::cout << "Untested : Returns a list of untested functions that can be called" << std::endl;
   
    } else {
      std::cout <<  std::endl <<  "Unkown command" << std::endl;
    }
#endif // DEBUG
  }
}

// OnLoad Called when we get attached to the game.
unsigned int __stdcall OnLoad(void* data) {

  // If we build in debug lets have a console window.
#ifdef _DEBUG

  AllocConsole();                  // Attach a console window.
  freopen("CONIN$", "r", stdin);   // Needed to read stuff.
  freopen("CONOUT$", "w", stdout); // Needed to print out stuff.
  freopen("CONOUT$", "w", stderr); // Needed to print out errors.

  std::cout << "==================================" << std::endl;
  std::cout << "| ANSDK Started." << std::endl;
  std::cout << "==================================" << std::endl << std::endl;

  // call the log so it get a fresh file.
  Log::getInstance()->log(Log::Note, "SDK started");

  // Initialize MinHook.
  MH_STATUS init = MH_Initialize();
  if (init != MH_OK) {
    Log::getInstance()->log(Log::Note, "ERROR: Minhook Could Not Initialize because: ", init);
  }
  else {
    Log::getInstance()->log(Log::Note, "MinHook initialized.");
    std::cout << "================================================" << std::endl;
    std::cout << "| MinHook initialized...Calling CreateHooks()" << std::endl;
    std::cout << "================================================" << std::endl << std::endl;

    if (CreateHooks()) {
      if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        std::cout << "Failed to start hooks...";
      }
      else {
        std::cout << std::endl << std::endl;
        std::cout << "All hooks enabled." << std::endl;
        std::cout << "=====================[All done ANSDK ready]===============" << std::endl << std::endl << std::endl;
      }
    }
#endif // DEBUG
    _beginthreadex(NULL, 0, &Update, NULL, 0, NULL);

    // Onload thread ends here.
  }
  return 0;
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
