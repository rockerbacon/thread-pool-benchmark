#include <benchmark_args_and_return.h>
#include <inkooboo/thread_pool.hpp>

class ThreadPoolAdapter : public tp::ThreadPool {
	public:
		template<
			typename func_type,
			typename... func_args
		>
		std::future<float> enqueue(func_type&& func, func_args&& ...args) {
			std::packaged_task<float()> task(std::bind(
				std::forward<func_type>(func),
				std::forward<func_args>(args)...
			));
			auto future = task.get_future();

			this->post(task);

			return future;
		}
};

int main() {

	BENCHMARK_ARGS_AND_RETURN(
		"inkooboo/thread-pool-cpp",
		ThreadPoolAdapter pool,
		pool.enqueue,
		/* no manual destruction */
	)


	return 0;
}
