#include "benchmark_skeleton.h"

#include <stopwatch/stopwatch.h>
#include <chrono>

using namespace std;
using namespace benchmark;

#define TASK_COUNT 100'000
#define RUNS 100

#define BENCHMARK_VOID_SIGNATURE(\
	POOL_IMPLEMENTATION,\
	INSTANTIATE_POOL,\
	PUSH_TASK,\
	DESTROY_POOL\
)\
	SETUP_BENCHMARK(INSTANTIATE_POOL);\
	RUN_BENCHMARK(\
		POOL_IMPLEMENTATION + " with void() method"s,\
		RUNS,\
		TASK_COUNT,\
		DESTROY_POOL,\
		void,\
		(),\
		/* no task */,\
		PUSH_TASK, /* no args */\
	)\

