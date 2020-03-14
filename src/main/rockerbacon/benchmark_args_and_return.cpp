#include <benchmark_args_and_return.h>
#include <rockerbacon/thread_pool.h>

#define THREADS std::thread::hardware_concurrency()

int main() {

	BENCHMARK_ARGS_AND_RETURN(
		"rockerbacon/parallel-tools",
		parallel_tools::thread_pool pool(THREADS),
		pool.exec,
		/* no manual destruction */
	)


	return 0;
}
