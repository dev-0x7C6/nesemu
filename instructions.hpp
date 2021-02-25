#pragma once

#include <registers.hpp>

namespace instruction {

template <typename type>
constexpr auto lda(registers::cpu &cpu, const type value) noexcept {
    cpu.A.u8 += value;
}

} // namespace instruction
