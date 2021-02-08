#include "mergesort.h"

#include <benchmark/benchmark.h>

static void BM_MergeSort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        int* data = GetRandomInput(state.range(0));
        state.ResumeTiming();
        MergeSort(data, state.range(0));
        free(data);
    }
}

BENCHMARK(BM_MergeSort)->RangeMultiplier(4)->Range(8, 8<<12);

BENCHMARK_MAIN();