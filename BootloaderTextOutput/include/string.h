#pragma once

#include "types.h"

uint16 stringLength( string characterStream )
{
  uint16 index = 0;

  while( true )
  {
    if ( characterStream[ index ] == '\0' ) { break; }
    index++;
  }

  return index;
}
