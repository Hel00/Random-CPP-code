First go into your llvm source code dir and run the `cmake -G Ninja ../llvm -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="" -DLLVM_TARGETS_TO_BUILD=all -DLLVM_BUILD_TOOLS=OFF -DBUILD_SHARED_LIBS=OFF` command

build with ninja `ninja LLVMAsmParser LLVMBitReader LLVMBitWriter -j4 -k 0`

the CMakeLists.txt file targets `/<your folder>/lib/cmake/llvm` so that it automatically sets up your project for you
