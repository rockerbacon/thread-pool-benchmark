#include <inkooboo/thread_pool.hpp>
#include <benchmark_void_signature.h>

#define THREADS std::thread::hardware_concurrency()

class ThreadPoolAdapter : public tp::ThreadPool {
	public:
		template<typename func_type>
		std::future<void> enqueue(func_type&& func) {
			std::packaged_task<void()> task(std::forward<func_type>(func));
			auto future = task.get_future();

			this->post(task);

			return future;
		}
};

int main (void) {
	BENCHMARK_VOID_SIGNATURE(
		"inkooboo/thread-pool-cpp",
		ThreadPoolAdapter pool,
		pool.enqueue,
		/* no manual destruction */
	);
	return 0;
}

