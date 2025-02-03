#include "steplab.h"
#include <benchmark/benchmark.h>
//#include <gtest/gtest.h>
#include <iostream>

//// Function to test, uses google test
//int add(int a, int b) {
//    return a + b;
//}
//
//// google test assertions
//TEST(AdditionTest, PositiveNumbers) {
//    EXPECT_EQ(add(2, 3), 5);
//}

static void BM_game (benchmark::State& state) {
    
    for (auto _ : state) {
        
        step_lab(100,10,100,10);
        benchmark::DoNotOptimize(step_lab);
    }
}

//BENCHMARK(BM_game)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_game);

BENCHMARK_MAIN();
