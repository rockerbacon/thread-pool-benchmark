#include <stopwatch/stopwatch.h>
#include <cpp-benchmark/benchmark.h>
#include <parallel-tools/thread_pool.h>
#include <ThreadPool/ThreadPool.h>
#include <thread>
#include <vector>

#define THREADS std::thread::hardware_concurrency()
#define TASKS_PER_RUN 20'000
#define RUNS 1'000

#define SETUP_BENCHMARK()\
	TerminalObserver terminal_observer;\
	chrono::high_resolution_clock::duration production_time,\
											consumption_time;\
	unsigned run;\
	float progress;\
\
	register_observers(terminal_observer);\
\
	observe(progress, percentage_complete);\
\
	observe_average(production_time, average_production_time);\
	observe_minimum(production_time, fastest_production_time);\
	observe_maximum(production_time, slowest_production_time);\
\
	observe_average(consumption_time, average_consumption_time);\
	observe_minimum(consumption_time, fastest_consumpion_time);\
	observe_maximum(consumption_time, slowest_consumption_time);\


using namespace benchmark;
using namespace std;

int main() {

	unsigned threads = THREADS;

	{
		SETUP_BENCHMARK();

		run = 0;
		parallel_tools::thread_pool pool(threads);
		benchmark("rockerbacon/parallel-tools with void() method", RUNS) {
			vector<future<void>> tasks_futures; tasks_futures.reserve(TASKS_PER_RUN);
			vector<chrono::high_resolution_clock::duration> tasks_consumption_time(TASKS_PER_RUN);
			vector<stopwatch> stopwatches(TASKS_PER_RUN);
			stopwatch stopwatch;

			for (unsigned i = 0; i < TASKS_PER_RUN; i++) {
				auto task = [
					&consumption_time = tasks_consumption_time[i],
				   	&stopwatch = stopwatches[i]
				] {
					consumption_time = stopwatch.lap_time();
				};

				tasks_futures.emplace_back(pool.exec(task));
			}
			production_time = stopwatch.lap_time();

			for (auto& future : tasks_futures) {
				future.wait();
			}
			consumption_time = *max_element(tasks_consumption_time.begin(), tasks_consumption_time.end());

			run++;
			progress = (float)run/RUNS*100.0f;
		}
	}

	{
		SETUP_BENCHMARK();

		run = 0;
		ThreadPool pool(threads);
		benchmark("progschj/ThreadPool with void() method", RUNS) {
			vector<future<void>> tasks_futures; tasks_futures.reserve(TASKS_PER_RUN);
			vector<chrono::high_resolution_clock::duration> tasks_consumption_time(TASKS_PER_RUN);
			vector<stopwatch> stopwatches(TASKS_PER_RUN);
			stopwatch stopwatch;

			for (unsigned i = 0; i < TASKS_PER_RUN; i++) {
				auto task = [
					&consumption_time = tasks_consumption_time[i],
				   	&stopwatch = stopwatches[i]
				] {
					consumption_time = stopwatch.lap_time();
				};

				tasks_futures.emplace_back(pool.enqueue(task));
			}
			production_time = stopwatch.lap_time();

			for (auto& future : tasks_futures) {
				future.wait();
			}
			consumption_time = *max_element(tasks_consumption_time.begin(), tasks_consumption_time.end());

			run++;
			progress = (float)run/RUNS*100.0f;
		}
	}
}
