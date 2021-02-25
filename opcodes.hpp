#pragma once

#include <cstddef>

namespace opcode {

using op = std::byte;

constexpr auto LDA = op{0xa9};
constexpr auto STA = op{0x8d};

consteval auto fetch_size(const op value) noexcept -> int {
    switch (value) {
        case LDA:
            return 1;
        case STA:
            return 2;
    }

    return 0;
}

} // namespace opcode
