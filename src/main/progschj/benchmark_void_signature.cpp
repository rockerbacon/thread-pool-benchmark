#include <progschj/ThreadPool.h>
#include <benchmark_void_signature.h>

#define THREADS std::thread::hardware_concurrency()

int main() {
	BENCHMARK_VOID_SIGNATURE(
		"progschj/ThreadPool",
		ThreadPool pool(THREADS),
		pool.enqueue,
		/* no manual destruction */
	);
	return 0;
}
