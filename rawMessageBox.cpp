// zig build-obj -lc -O ReleaseSmall -fstrip rawMessageBox.cpp
// zig lld-link /entry:Main /subsystem:console test.obj "C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um\x64\User32.Lib"

int MessageBoxA(
  int   hWnd,
  const char* lpText,
  const char* lpCaption,
  int   uType
) asm("MessageBoxA");

extern "C" int Main()
{
  MessageBoxA(0, "Hello World!", "Output:", 0);

  return 0;
}
