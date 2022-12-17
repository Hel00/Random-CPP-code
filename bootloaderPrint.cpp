/* COMPILED WITH */

// z++ main.cpp --target=i386-freestanding-none -Oz -s -c -m16
// objcopy -O binary main.o main.bin --change-section-address .text=0x7C00
// qemu-system-x86_64 -hda main.bin

asm
(
  R"(
    .intel_syntax;

    _start:
    mov ah, 0xe;
    mov al, 'A';
    //mov bx, 0;

    .byte 0xBB
    .byte 0x00
    .byte 0x00

    int 0x10;

    loop:
    jmp loop

    .rept 249
    .short 0x0000
    .endr
    .byte 0x00
    .byte 0x55
    .byte 0xAA

    .att_syntax;
  )"
);

/* NASM */

/*
org 0x7C00
bits 16

start:
  mov ah, 0eh
  mov al, 'A'
  mov bx, 0
  int 0x10

  jmp $

times 510-($ - $$) db 0
dw 0xAA55
*/

/* BINARY */

/*
00000000  B40E              mov ah,0xe
00000002  B041              mov al,0x41
00000004  BB0000            mov bx,0x0
00000007  CD10              int 0x10
00000009  EBFE              jmp short 0x9
...
0000
0055AA
*/
