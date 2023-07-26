#pragma once

#include "types.h"
#include "system.h"
#include "string.h"

uint32 cursorX = 0;
uint32 cursorY = 0;

const uint8 screenWidth = 80;
const uint8 screenHeight = 25;
const uint8 screenDepth = 2;

void clearLine( uint8 from, uint8 to )
{
  string videoMemory = (string) 0xB8000;

  for ( uint16 index = screenWidth * from * screenDepth;
        index < ( screenWidth * ( to + 1) * screenDepth );
        index++ )
  {
    videoMemory[ index++ ] = 0x00;
  }
}

void updateCursor()
{
  uint32 currentPosition = cursorY * screenWidth + cursorX;

  outputPortByte (          0x3D4, 14          ); // CRT Control Register: Select Cursor Location
  outputPortByte ( 0x3D5, currentPosition >> 8 ); // Send the high byte across the bus
  outputPortByte (          0x3D4, 15          ); // CRT Control Register: Select Send Low byte
  outputPortByte (    0x3D5, currentPosition   ); // Send the Low byte of the cursor location
}

void clearScreen()
{
  clearLine( 0 , screenHeight - 1 );
  cursorX = 0;
  cursorY = 0;
  updateCursor();
}

void scrollUp( uint8 lineNumber )
{
  string videoMemory = (string) 0xB8000;

  for ( uint16 index = 0;
        index < screenWidth * ( screenHeight - 1 ) * screenDepth;
        index++ )
  {
    videoMemory[ index ] = videoMemory[ index
                                      + screenWidth
                                      * screenDepth
                                      * lineNumber ];
  }

  clearLine( screenHeight - 1 - lineNumber, screenHeight - 1 );

  if ( ( cursorY - lineNumber ) < 0 )
  {
    cursorX = 0;
    cursorY = 0;
  }
  else
  {
    cursorY -= lineNumber;
  }

  updateCursor();
}

void newLineCheck()
{
  if ( cursorY >= screenHeight - 1 )
  {
    scrollUp( 1 );
  }
}

void printCharacter( char character )
{
  string videoMemory = (string) 0xB8000;

  switch( character )
  {
  case( 0x08 ):
    if ( cursorX > 0 )
    {
      cursorX--;
      videoMemory[ ( cursorY * screenWidth + cursorX ) * screenDepth ] = 0x00;
    }
    break;

  case( 0x09 ):
    cursorX = ( cursorX + 8 ) & ~ ( 8 - 1 );
    break;

  case( '\r' ):
    cursorX = 0;
    break;

  case( '\n' ):
    cursorX = 0;
    cursorY++;
    break;

  default:
    videoMemory[ ( ( cursorY * screenWidth + cursorX ) ) * screenDepth ] = character;
    videoMemory[ ( ( cursorY * screenWidth + cursorX ) ) * screenDepth + 1 ] = 0x0F;
    cursorX++;
    break;
  }
}

void print( const string characterStream )
{
  for ( uint16 index = 0; index < stringLength( characterStream ); index++ )
  {
    printCharacter( characterStream[ index ] );
  }
}
