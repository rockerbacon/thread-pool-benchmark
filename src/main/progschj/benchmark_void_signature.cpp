#include <progschj/ThreadPool.h>
#include <benchmark_void_signature.h>

#define THREADS std::thread::hardware_concurrency()

int main() {
	BENCHMARK_VOID_SIGNATURE(
		"progschj/ThreadPool"s,
		ThreadPool pool(THREADS),
		pool.enqueue,

	);
	return 0;
}
