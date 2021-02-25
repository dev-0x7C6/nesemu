#pragma once

#include <cstdint>

namespace registers {

union reg8 {
    std::uint8_t u8;
    std::int8_t i8;
};

union reg16 {
    std::uint16_t u16;
    std::int16_t i16;
};

struct reg_flags {
    bool b0 : 1;
    bool b1 : 1;
    bool b2 : 1;
    bool b3 : 1;
    bool b4 : 1;
    bool b5 : 1;
    bool b6 : 1;
    bool b7 : 1;
};

static_assert(sizeof(reg8) == 1);
static_assert(sizeof(reg16) == 2);
static_assert(sizeof(reg_flags) == 1);

struct cpu {
    reg8 A{};
    reg8 X{};
    reg8 Y{};
    reg8 S{};
    reg_flags F{};
    reg16 PC{};
};

} // namespace registers
