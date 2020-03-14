#include <benchmark_args_and_return.h>
#include <mtrebi/ThreadPool.h>

#define THREADS std::thread::hardware_concurrency()

int main() {

	BENCHMARK_ARGS_AND_RETURN(
		"mtrebi/ThreadPool",
		ThreadPool pool(THREADS); pool.init(),
		pool.submit,
		pool.shutdown()
	)


	return 0;
}
