
zig c++ --target=x86_64-linux -std=c++20 -fmodules -fbuiltin-module-map -c moduleTest.cpp
zig c++ --target=x86_64-linux -std=c++20 -fmodules -fbuiltin-module-map -fprebuilt-module-path=. -c main.cpp -o main.o
zig c++ --target=x86_64-linux -std=c++20 -fmodules -fbuiltin-module-map main.o moduleTest.o -o main
