# Resource structure 

Size: 40bytes

| Type  | Name |
| ------------- | ------------- |
| int32_t   | unknown  |
| int32_t   | resourceid  |
| char[4]   | unknown  |
| int32_t   | amount  |
| char[24]   | unknown  |


Notes:
- First unknown might be some sort of base type id. Almost always 40477080 but also 40686384.(seems 40686384 is for usable resources like maps)
- Second unknown affects your savegame.
- Last 24 bytes of padding are almost always 0

Resource id's:

| Id  | Name |
| ------------- | ------------- |
| 1   | Money  |
| 5   | Smoke bombs  |
| 8   | Throwing knifes  |
| 11   | Gun ammo  |
| 32   | Rope darts  |
| 35   | Sleep darts  |
| 36   | Berserk darts  |
| 41   | Wood  |
| 42   | Metal  |
| 43   | Textile  |
| 44   | Rum  |
| 45   | Sugar  |
| 47   | Heavy shot  |
| 48   | Mortar shot  |
| 49   | Fire barrels  |
