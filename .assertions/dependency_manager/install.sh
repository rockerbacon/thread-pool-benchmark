#!/bin/bash
apt-package/install.sh g++
apt-package/install.sh cmake
apt-package/install.sh make
git/install.sh https://github.com/progschj/ThreadPool.git 9a42ec1329f259a5f4881a291db1dcb8f2ad9040 false "." "." "rm example.cpp"
git/install.sh https://github.com/rockerbacon/parallel-tools.git v1.0.2 false "src/objs" "src/objs" ""
git/install.sh https://github.com/rockerbacon/cpp-benchmark.git v1.0.5 false "src/objs" "src/objs" ""
git/install.sh https://github.com/rockerbacon/stopwatch.git v2.1.4 false "src/objs" "src/objs" ""
git/install.sh https://github.com/mtrebi/thread-pool.git 1c80f3abfda89afcacfb39a8e892aeb8eed0c299 false "include" "include" ""
