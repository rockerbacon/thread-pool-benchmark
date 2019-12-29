#include <stopwatch/stopwatch.h>
#include <cpp-benchmark/benchmark.h>
#include <parallel-tools/thread_pool.h>
#include <thread>
#include <vector>

#define TASKS_TO_PROCESS 1'000'000

using namespace benchmark;
using namespace std;

void empty_signature_method() {
}

int main() {
	TerminalObserver terminal_observer;
	chrono::high_resolution_clock::duration production_time,
											consumption_time;

	unsigned run = 0;
	float progress;

	register_observers(terminal_observer);

	observe(progress, percentage_complete);

	observe_average(production_time, average_production_time);
	observe_minimum(production_time, fastest_production_time);
	observe_maximum(production_time, slowest_production_time);

	observe_average(consumption_time, average_consumption_time);
	observe_minimum(consumption_time, fastest_consumpion_time);
	observe_maximum(consumption_time, slowest_consumption_time);

	{
		parallel_tools::thread_pool pool(1);
		benchmark("rockerbacon/parallel-tools with void() method", TASKS_TO_PROCESS) {
			stopwatch stopwatch;

			auto future = pool.exec(empty_signature_method);
			production_time = stopwatch.lap_time();

			future.wait();
			consumption_time = stopwatch.lap_time();

			run++;
			progress = (float)run/TASKS_TO_PROCESS*100.0f;
		}
	}

}
