#include <instructions.hpp>
#include <opcodes.hpp>
#include <registers.hpp>

#include <concepts>
#include <functional>
#include <ranges>
#include <vector>

constexpr auto simple_lda_program = {
    std::byte{0xa9},
    std::byte{0x01},
    std::byte{0xa9},
    std::byte{0x02},
    std::byte{0xa9},
    std::byte{0x04}};

struct memory {
    std::byte *ptr{nullptr};
    constexpr auto fetch() noexcept { return *ptr++; };
};

constexpr auto process_single_instruction(registers::cpu &state, memory &mem) {
    switch (mem.fetch()) {
        case opcode::LDA:
            instruction::lda(state, mem.fetch());
    }
}

auto process(registers::cpu &cpu) {
    std::vector<std::byte> bytes = simple_lda_program;

    memory mem{bytes.data()};

    process_single_instruction(cpu, mem);
    process_single_instruction(cpu, mem);
    process_single_instruction(cpu, mem);
}

auto main(int, char **) -> int {
    registers::cpu cpu;
    process(cpu);
    return cpu.A.i8;
}
