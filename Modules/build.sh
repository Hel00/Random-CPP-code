clang++ -Oz -s -std=c++20 -fmodules -fbuiltin-module-map -Xclang -emit-module-interface -S -emit-llvm moduleTest.cpp -o moduleTest.pcm
clang++ -Oz -s -std=c++20 -fmodules -fbuiltin-module-map -S -emit-llvm moduleTest.cpp
clang++ -Oz -s -std=c++20 -fmodules -fbuiltin-module-map -fprebuilt-module-path=. -S -emit-llvm main.cpp -o main.ll

z++ -Oz -s -std=c++20 -fmodules -fbuiltin-module-map main.ll moduleTest.ll -o main
