// zig build-exe -O ReleaseSmall -ffunction-sections --gc-sections --entry Main freestandingMessageBoxA.cpp

// zig build-exe -target x86_64-windows-none -L"/home/hel/.wine/drive_c/windows/system32/" -dynamic -lkernel32 -luser32 freestandingMessageBoxA.cpp

// z++ freestandingMessageBoxA.cpp -Os -s --target=x86_64-windows-none -nostdlib -nostdinc -nostdinc++ -nostartfiles -L"/home/hel/.wine/drive_c/windows/system32/" "-Wl,--subsystem,native" -dynamic -lkernel32 -luser32

extern "C" int MessageBoxA(
  int   hWnd,
  const char* lpText,
  const char* lpCaption,
  int   uType
) asm("MessageBoxA");

extern "C" void Main() __attribute__((constructor));

extern "C" void Main()
{
  MessageBoxA(0, "Hello World!", "Output:", 0);
}

void wWinMainCRTStartup() { Main(); }
