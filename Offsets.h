/*
| License: Unlicense
| Created by: Lambdarevolution(at)gmail.com / 2020-04-01
| Description: Named offsets but in reality they are patterns as i dont trust static offsets, unless i really have too..
| Might rename this at some point or simply add pattern namespace as offsets will be used...
*/
#ifndef OFFSETS_H
#define OFFSETS_H

namespace Offsets {
  // Pattern, mask..there is problaby a cleaner way doing this but whatever...
  static const char* const ExitProcess[] = { "\xE8\x00\x00\x00\x00\x83\xC4\x04\xFF\x15\x00\x00\x00\x00\x8A\xD8", "x????xxxxx????xx" };
  static const char* const GetWeaponName[] = { "\x55\x8B\xEC\x8B\x45\x08\x83\xF8\x22", "xxxxxxxxx" };
  static const char* const SetPlayerHealth[] = { "\x55\x8B\xEC\x8B\x45\x08\x8B\x50\x0C\x8B\x40\x10", "xxxxxxxxxxxx" };
  static const char* const ReduceResource[] = { "\x55\x8B\xEC\x8B\x41\x0C\x8B\x55\x08\x3B\xC2", "xxxxxxxxxxx" };
  static const char* const ShipHealth[] = { "\x55\x8B\xEC\xF3\x0F\x10\x45\x00\x83\xEC\x08\x56\x8B\xF1\xF3\x0F\x10\x8E\x00\x00\x00\x00", "xxxxxxx?xxxxxxxxxx????" };
  static const char* const PlayerSwap[] = { "\x89\x4E\x04\x8B\x4D\x1C\x89\x46\x0C", "xxxxxxxxx" }; // ?
  static const char* const Aiming[] = { "\x50\x8D\x45\x14\x50\xE8\x00\x00\x00\x00 ", "xxxxxx????" };
}                                            
#endif
