#include <benchmark_args_and_return.h>
#include <progschj/ThreadPool.h>

#define THREADS std::thread::hardware_concurrency()

int main() {

	BENCHMARK_ARGS_AND_RETURN(
		"progschj/ThreadPool",
		ThreadPool pool(THREADS),
		pool.enqueue,
		/* no manual destruction */
	)


	return 0;
}
