set CXX=clang++ --std=c++20 -fmodules-ts -Oz -s --target=x86_64-pc-windows-gnu

%CXX% -o split.pcm  --precompile -x c++-module split.cpp
%CXX% -o main.exe -fprebuilt-module-path=. main.cpp split.cpp

z++ --std=c++20 -fmodules-ts --precompile -x c++-module -c split.cpp -o split.pcm
z++ --std=c++20 -fmodules-ts -o main.exe -fprebuilt-module-path=. main.cpp split.cpp
