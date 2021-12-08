namespace lambdasdk {
  namespace player {

    // Returns the current health (0-200)
    // No Need for an internal function we use pointers to the address right away instead.
    int GetHealth() {
      DWORD BaseAddress = (DWORD)GetModuleHandle(L"AC4BFSP.exe") + 0x049DF788;
      uintptr_t PlayerHealthAddress = FindDMAAddy(BaseAddress, { 0x34, 0x84 });
    
      return *(int*)PlayerHealthAddress;
    }
  }
}
