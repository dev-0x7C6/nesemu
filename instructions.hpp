#pragma once

#include <registers.hpp>
#include <opcodes.hpp>

namespace instruction {

template <typename type>
constexpr auto lda(registers::cpu &cpu, const type value) noexcept {
    cpu.A.u8 += static_cast<std::uint8_t>(value);
}

} // namespace instruction
