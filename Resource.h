/*
| License: Unlicense
| Created by: Lambdarevolution(at)gmail.com / 2021-12-20
| Description: resource class.
*/
#ifndef RESOURCE_H
#define RESOURCE_H

#include <stdint.h>
class resource {
public:
  int32_t resourcetype; //0x0000
  int32_t resourceid; //0x0004
  char pad_0008[4]; //0x0008
  int32_t amount; //0x000C
  char pad_0010[24]; //0x0010
};
#endif  // RESOURCE_H
