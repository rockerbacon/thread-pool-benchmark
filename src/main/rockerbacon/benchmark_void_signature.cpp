#include <rockerbacon/thread_pool.h>
#include <benchmark_void_signature.h>

#define THREADS std::thread::hardware_concurrency()

int main (void) {
	BENCHMARK_VOID_SIGNATURE(
		"rockerbacon/parallel-tools",
		parallel_tools::thread_pool pool(THREADS),
		pool.exec,
		/* no manual destruction */
	);
	return 0;
}

