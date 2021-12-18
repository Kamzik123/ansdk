/*
| License: Unlicense, do what you want with it.
| Created by: Lambdarevolution(at)gmail.com / 2021-12-17
| Description: Named offsets but in reality they are patterns as i dont trust static offsets, unless i really have too even old games might get a suprise update...
|  Might split this up later as some static offsets will be required.
*/
#ifndef OFFSETS_H
#define OFFSETS_H

// NOTE: Only add patterns you can confirm works.
namespace Offsets {
  
  // Pattern, mask..there is problaby a cleaner way doing this but whatever...works for our purposes and cpp check wont cry about defines.
  static const char* const ExitProcess[] =       { "\xE8\x00\x00\x00\x00\x83\xC4\x04\xFF\x15\x00\x00\x00\x00\x8A\xD8", "x????xxxxx????xx" };
  static const char* const GetWeaponName[] =     { "\x55\x8B\xEC\x8B\x45\x08\x83\xF8\x22", "xxxxxxxxx" };
  static const char* const SetPlayerHealth[] =   { "\x55\x8B\xEC\x8B\x45\x08\x8B\x50\x0C\x8B\x40\x10", "xxxxxxxxxxxx" };

}
#endif
