// zcc test.cpp -s --target=x86_64-windows -L"/home/hel/.wine/drive_c/windows/system32/" -l:kernel32.dll -l:user32.dll

// zig build-exe -target x86_64-windows -L"/home/hel/.wine/drive_c/windows/system32/" -dynamic -lkernel32 -luser32 -lc test.cpp

extern "C" int MessageBoxA(
  int   hWnd,
  const char* lpText,
  const char* lpCaption,
  int   uType
) asm("MessageBoxA");

extern "C" void Main() __attribute__((constructor));

extern "C" void Main()
{
  //MessageBoxA(0, "Hello World!", "Output:", 0);
}

int main()
{
  MessageBoxA(0, "Hello World!", "Output:", 0);
}
