#pragma once

#include "types.h"

uint8 inputPortByte( uint16 port )
{
  uint8 result;

  asm volatile ( "inb %1, %0" : "=a" ( result ) : "dN" ( port ) );

  return result;
}

void outputPortByte( uint16 port, uint8 data )
{
  asm volatile ("outb %1, %0" : : "dN" ( port ), "a" ( data ) );
}

/*
This code defines two functions, inputPortByte and outputPortByte, that allow a program to read from and write to I/O ports, respectively.

The inputPortByte function reads a single byte from the specified I/O port and returns it.

The port is specified by the argument port, which is a 16-bit unsigned integer.

The function uses the inb assembly instruction to read a byte from the port and stores the result in the result variable, which is an 8-bit unsigned integer.

The outputPortByte function writes a single byte to the specified I/O port.

The port is specified by the argument port, which is a 16-bit unsigned integer, and the data to be written is specified by the argument data, which is an 8-bit unsigned integer.

The function uses the outb assembly instruction to write the data to the port.

Both functions use the asm keyword to embed assembly instructions directly in the C++ code.

The asm keyword is followed by a string that contains the assembly instructions, surrounded by quotation marks.

The volatile keyword ensures that the compiler does not optimize away the assembly instructions, as they have side effects (reading from or writing to I/O ports).

The %0 and %1 symbols in the assembly instructions represent the inputs and outputs of the assembly instructions, respectively.

The %0 symbol is replaced with the first output specified after the : symbol (in this case, result for the inputPortByte function and port for the outputPortByte function),
and the %1 symbol is replaced with the first input specified after the : symbol (in this case, port for the inputPortByte function and data for the outputPortByte function).

The : "=a" ( result ) and : : "dN" ( port ),
"a" ( data ) expressions are called "constraints" and they specify how the inputs and outputs of the assembly instructions should be mapped to registers or memory locations.

In this case, the "=a" constraint specifies that the output (result for the inputPortByte function and port for the outputPortByte function) should be stored in the eax register,
and the "dN" constraint specifies that the input (port for the inputPortByte function and data for the outputPortByte function) should be stored in the edx register.

The "a" constraint specifies that the input (data for the outputPortByte function) should be stored in the eax register.

I/O ports are special memory-mapped locations that allow a program to communicate with hardware devices, such as keyboards, printers, and network adapters.

The inb and outb instructions allow a program to read from and write to I/O ports, respectively.

These instructions are part of the x86 instruction set, which is the instruction set used by most computers with Intel or AMD processors.
*/
