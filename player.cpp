/*
| License: Unlicense, do what you want with it.
| Created by: Lambdarevolution(at)gmail.com / 2021-12-17
| Description: Player struct....
*/
// The base pointer is still disputed
struct player() {
// will update in a bit
}


// Doodles below ignore most of this
// Far From complete, might be wrong base, even tho it still a valid pointer that can be used for the real base
Offset: 08  - HUD - HEALTHBAR Some sort of z-order value? 0 = hidden 100+ and it shows in menus aswell. Jumps all over // byte
Offset 84 - Health 0-200 // 2 or 4 bytes?
Offset 88 - Max Health(?) // it's used for something in health.
Offset: 0288 - Wanted level of some sort, it only affects 1st wanted level for some reason // byte
Offset: 041C - X/Y (?) // float
Offset: 0408 Z?  // float
Offset: 0034 // 0 = health bar shows - 10000 it's hidden (cut off at 2099) - So flag? Or not a 4-byte type

Offset: 808 1 when running, 0 otherwise
Offset: 894 changes when using scrollwheel
Offset: 824 When idle 1 Otherwise: 0 when aiming
Offset: 89C When aiming: 72 otherwise 0
0ffset: 6E8 3/4 When aiming with gun. unkown size
0ffset: 8F8: 0 - Normal - 164 When Hidden
Offset: 900: 0 Normal Hit/Hold Left shift = 42
Offset: 7C0 2 when aiming at npc - 0 otherwise <- modifies ui rectile
Offset: 7BC 2 when aiming at npc - 0 otherwise
Offset: 8CC 0 when hidden 1 otherwise
Offset: 524 4 when in menu
