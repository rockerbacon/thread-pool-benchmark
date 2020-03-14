#pragma once

#include <stopwatch/stopwatch.h>
#include <cpp-benchmark/benchmark.h>
#include <future>
#include <vector>

#define SETUP_BENCHMARK(INSTANTIATE_POOL)\
	benchmark::TerminalObserver observer;\
\
	std::chrono::high_resolution_clock::duration production_time,\
											consumption_time,\
											delay;\
\
	unsigned run;\
	unsigned progress;\
\
	register_observers(observer);\
\
	observe(progress, percentage_completed);\
\
	observe_average(production_time, avg_production_time);\
	observe_minimum(production_time, min_production_time);\
	observe_maximum(production_time, max_production_time);\
\
	observe_average(consumption_time, avg_consumption_time);\
	observe_minimum(consumption_time, min_consumption_time);\
	observe_maximum(consumption_time, max_consumption_time);\
\
	observe_average(delay, avg_delay);\
	observe_minimum(delay, min_delay);\
	observe_maximum(delay, max_delay);\
\
	run = 0;\
	INSTANTIATE_POOL;\

#define RUN_BENCHMARK(\
	TITLE,\
	RUNS,\
	TASK_COUNT,\
	DESTROY_POOL,\
	RETURN_TYPE,\
	ARGS_SIGNATURE,\
	TASK,\
	PUSH_TASK,\
	...\
)\
	benchmark(TITLE, RUNS) {\
		std::vector<std::future<RETURN_TYPE>> tasks_futures;\
		tasks_futures.reserve(TASK_COUNT);\
		vector<decltype(consumption_time)> consumption_times(TASK_COUNT);\
		vector<stopwatch> tasks_stopwatches(TASK_COUNT);\
\
		stopwatch production_stopwatch;\
		for (decltype(TASK_COUNT) i = 0; i < TASK_COUNT; i++) {\
			auto future = PUSH_TASK(\
				[\
					&consumption_time = consumption_times[i],\
					&stopwatch = tasks_stopwatches[i]\
				] ARGS_SIGNATURE {\
					consumption_time = stopwatch.lap_time();\
					TASK;\
				}\
				__VA_ARGS__\
			);\
			tasks_futures.emplace_back(std::move(future));\
		}\
		production_time = production_stopwatch.total_time();\
\
		for(auto& future : tasks_futures) future.wait();\
\
		consumption_time = *std::max_element(\
			consumption_times.begin(),\
			consumption_times.end()\
		);\
\
		delay = consumption_time - production_time;\
		run++;\
		progress = (float)run/RUNS*100.0f;\
	}\
	DESTROY_POOL;\

