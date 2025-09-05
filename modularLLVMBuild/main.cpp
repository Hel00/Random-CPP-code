#include "llvm/AsmParser/Parser.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"

int main() {
    llvm::LLVMContext ctx;
    llvm::SMDiagnostic err;

    // Parse a trivial IR string
    const char *IR = "define i32 @main() { ret i32 0 }";
    std::unique_ptr<llvm::MemoryBuffer> buf =
        llvm::MemoryBuffer::getMemBuffer(IR);

    std::unique_ptr<llvm::Module> mod =
        parseAssembly(*buf, err, ctx);

    if (!mod) {
        err.print("tiny", llvm::errs());
        return 1;
    }

    mod->print(llvm::outs(), nullptr);
    return 0;
}
