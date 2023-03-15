clang++ -std=c++20 -fmodules -fbuiltin-module-map -fmodules-ts -Xclang -emit-module-interface -c moduleTest.cpp -o moduleTest.pcm
clang++ -std=c++20 -fmodules -fbuiltin-module-map -c moduleTest.cpp
clang++ -std=c++20 -fmodules -fbuiltin-module-map -fprebuilt-module-path=. -c main.cpp -o main.o
clang++ -std=c++20 -fmodules -fbuiltin-module-map main.o moduleTest.o -o main

#-stdlib=libc++
