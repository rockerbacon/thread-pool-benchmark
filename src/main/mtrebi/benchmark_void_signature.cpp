#include <mtrebi/ThreadPool.h>
#include <benchmark_void_signature.h>

#define THREADS std::thread::hardware_concurrency()

int main() {
	BENCHMARK_VOID_SIGNATURE(
		"mtrebi/thread-pool"s,
		ThreadPool pool(THREADS); pool.init(),
		pool.submit,
		pool.shutdown()
	);
	return 0;
}
