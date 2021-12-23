/*
| License: Unlicense
| Created by: Lambdarevolution(at)gmail.com / 2020-04-01
| Description: Named offsets but in reality they are patterns as i dont trust static offsets, unless i really have too..
| Might rename this at some point or simply add pattern namespace as offsets will be used...
*/
#ifndef OFFSETS_H
#define OFFSETS_H

// Defines are evil blabla but this speeds up testing..
#define pattern(name, bytes, mask) static const char* const name[] = { bytes, mask };

namespace Offsets {

  // Name, pattern, mask..there is problaby a cleaner way doing this but whatever it's good enough
  pattern(ExitProcess,"\xE8\x00\x00\x00\x00\x83\xC4\x04\xFF\x15\x00\x00\x00\x00\x8A\xD8", "x????xxxxx????xx");
  pattern(GetWeaponName, "\x55\x8B\xEC\x8B\x45\x08\x83\xF8\x22", "xxxxxxxxx");
  pattern(SetPlayerHealth, "\x55\x8B\xEC\x8B\x45\x08\x8B\x50\x0C\x8B\x40\x10", "xxxxxxxxxxxx");
  pattern(ReduceResource, "\x55\x8B\xEC\x8B\x41\x0C\x8B\x55\x08\x3B\xC2", "xxxxxxxxxxx"); // Bad name? it also adds...
  pattern(ShipHealth, "\x55\x8B\xEC\xF3\x0F\x10\x45\x00\x83\xEC\x08\x56\x8B\xF1\xF3\x0F\x10\x8E\x00\x00\x00\x00", "xxxxxxx?xxxxxxxxxx????");
  pattern(PlayerSwap, "\x89\x4E\x04\x8B\x4D\x1C\x89\x46\x0C", "xxxxxxxxx");
  pattern(Aiming, "\x50\x8D\x45\x14\x50\xE8\x00\x00\x00\x00", "xxxxxx????");
  pattern(HideHudElement, "\x74\x05\x83\xF8\x03\x75\x20", "xxxxxxx");
  pattern(OnKeyDown, "\x8B\xEC\x83\xEC\x28\x57\x8B\xF9\x8B\x0F", "xxxxxxxxxx");
  pattern(CityEvent, "\xE8\x00\x00\x00\x00\x83\xC4\x08\x83\x3F\x00\x75\x0C", "x????xxxxxxxx");
  pattern(crosshair_color, "\xD9\x40\x08\xD9\x59\x74", "xxxxxx"); 
  pattern(HudActionButtonsDraw, "\x55\x8B\xEC\x8B\x45\x08\x83\xEC\x5C\x56\x50", "xxxxxxxxxxx"); 
  pattern(Player_Marker_Add, "\x55\x8B\xEC\x83\xEC\x14\xA1\x00\x00\x00\x00\x56\x57\x6A\x1E", "xxxxxxx????xxxx");
  pattern(shipkill_pattern, "\x55\x8B\xEC\x51\x56\x8B\xF1\xE8\x00\x00\x00\x00\x89\x45\xFC\x85\xC0", "xxxxxxxx????xxxxx"); // ?
  pattern(Show_Repair_Ship_Something, "\x55\x8B\xEC\x83\xEC\x3C\x53\x56\x8B\xF1\x8B\x86\x00\x00\x00\x00", "xxxxxxxxxxxx????"); // This needs a new name...
  pattern(Forge_Name_Related, "\xE8\x00\x00\x00\x00\x83\xC4\x14\x8D\x8D\x00\x00\x00\x00\x8B\xF8", "x????xxxxx????xx"); // ?
  pattern(Find_Forge_Files, "\xE8\x00\x00\x00\x00\x83\xC6\x04\x3B\xF3\x75\xED\x8B\x87\x00\x00\x00\x00", "x????xxxxxxxxx????"); // ?
  pattern(ForgeFileRead, "\xE8\x00\x00\x00\x00\xEB\x23\x8B\x33", "x????xxxx"); // ?
  pattern(ForgeCreateFile, "\xE8\x00\x00\x00\x00\x83\xC4\x04\x8A\xD8\x85\xF6", "x????xxxxxxx"); // ?
  pattern(SetShipSpeed, "\xE8\x00\x00\x00\x00\x8B\x8E\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x96\x00\x00\x00\x00", "x????xx????x????xx????"); // ?
  pattern(Add_Upgrade_Ship, "\x55\x8B\xEC\x83\xEC\x28\x53\x56\x57\x8B\xF1\x33\xDB", "xxxxxxxxxxxxx"); // Could be something else
  pattern(Show_Image_Something, "\x55\x8B\xEC\x83\xEC\x28\x53\x56\x57\x8B\xF1\x33\xDB", "xxxxxxxxxxxxx"); //  not implemented.
  pattern(ConflictIcon, "\x55\x8B\xEC\x53\x8B\x5D\x08\x56\x57\x53\x8B\xF9\xE8\x00\x00\x00\x00\x8B\xF0\x85\xF6\x0F\x95\x45\x0B\x85\xF6\x74\x0F", "xxxxxxxxxxxxx????xxxxxxxxxxxx"); // Crashes?.


  // Engine related patterns
  pattern(Get_InI_Int, "\x55\x8B\xEC\x53\x56\x8B\x75\x08\x6A\x08", "xxxxxxxxxx");
  pattern(Add_Dlc_Packgage, "\x55\x8B\xEC\x83\xEC\x10\x53\x56\x57\xBF\x00\x00\x00\x00", "xxxxxxxxxx????"); // not implemented yet
  pattern(AddSubtext, "\xE8\x00\x00\x00\x00\xE9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x16", "x????x????x????xx");

  namespace Pointers {
    static const int Player[] { 0x3C, 0xE8, 0x1C, 0x5C, 0x0, 0xC, 0x0, 0x0 }; 
    static const int PlayerShip[]{ 0x4, 0x4, 0xC, 0x4C, 0x38, 0xC, 0x2C, 0x208 }; 
  }
}                                            
#endif
