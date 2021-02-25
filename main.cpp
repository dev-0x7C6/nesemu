#include <instructions.hpp>
#include <opcodes.hpp>
#include <registers.hpp>

auto main(int, char **) -> int {
    registers::cpu cpu;
    instruction::lda(cpu, 1);
    instruction::lda(cpu, 1);
    instruction::lda(cpu, 1);
    return cpu.A.i8;
}
