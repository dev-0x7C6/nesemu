#include <benchmark/benchmark.h>
#include <instructions.hpp>
#include <registers.hpp>

static void simple_lda_func(benchmark::State &state) {

	registers::cpu cpu;
	while (state.KeepRunning()) {
		instruction::lda(cpu, 1);
		benchmark::DoNotOptimize(cpu.A);
	}
}

BENCHMARK(simple_lda_func);

auto main(int argc, char **argv) -> int {
	::benchmark::Initialize(&argc, argv);
	::benchmark::RunSpecifiedBenchmarks();
	return 0;
}
