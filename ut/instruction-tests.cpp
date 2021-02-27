#include <gtest/gtest.h>

#include <instructions.hpp>
#include <registers.hpp>

TEST(Instructions, LDA) {
	registers::cpu cpu;
	EXPECT_EQ(cpu.A.u8, 0);
	instruction::lda(cpu, 1);
	EXPECT_EQ(cpu.A.u8, 1);
	instruction::lda(cpu, 254);
	EXPECT_EQ(cpu.A.u8, 255);
	instruction::lda(cpu, 1);
	EXPECT_EQ(cpu.A.u8, 0);
}

