/*
| License: Unlicense
| Created by: Lambdarevolution(at)gmail.com / 2021-12-01
| Description: patterns, not final...
*/
#ifndef PATTERNS_H
#define PATTERNS_H

namespace Patterns {
// Will add them soon...
 
// const char* GetWeaponNameFromType(int,int)  "\x55\x8B\xEC\x8B\x45\x08\x83\xF8\x22", "xxxxxxxxx"
// const char* GetBoatNameFromType(int) "\x55\x8B\xEC\x8B\x45\x08\x48\x83\xF8\x0A\x77\x6A", "xxxxxxxxxxxx"
// void SetShipHealth(void*, float) "\x55\x8B\xEC\xF3\x0F\x10\x45\x00\x83\xEC\x08\x56\x8B\xF1\xF3\x0F\x10\x8E\x00\x00\x00\x00", "xxxxxxx?xxxxxxxxxx????"

}   

namespace Pointers {
 static const int Player[] { 0x3C, 0xE8, 0x1C, 0x5C, 0x0, 0xC, 0x0, 0x0 }; 
 static const int PlayerShip[]{ 0x4, 0x4, 0xC, 0x4C, 0x38, 0xC, 0x2C, 0x208 }; 
}
#endif
