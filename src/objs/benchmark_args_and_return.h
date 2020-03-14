#include "benchmark_skeleton.h"

#include <stopwatch/stopwatch.h>
#include <chrono>
#include <random>

using namespace std;
using namespace benchmark;

#define TASK_COUNT 100'000
#define RUNS 100

#define BENCHMARK_ARGS_AND_RETURN(\
	POOL_IMPLEMENTATION,\
	INSTANTIATE_POOL,\
	PUSH_TASK,\
	DESTROY_POOL\
)\
{\
	std::random_device rand_device;\
	std::mt19937 rand_engine(rand_device());\
	std::uniform_int_distribution<int> rand_int(5, 20);\
	std::uniform_real_distribution<float> rand_float(5.0, 20.0);\
	\
	SETUP_BENCHMARK(INSTANTIATE_POOL);\
	RUN_BENCHMARK(\
		POOL_IMPLEMENTATION + " with float(int,float) method"s,\
		RUNS,\
		TASK_COUNT,\
		DESTROY_POOL,\
		float, (int a, float b),\
		return (float)a+b,\
		PUSH_TASK,, rand_int(rand_engine), rand_float(rand_engine)\
	)\
}

