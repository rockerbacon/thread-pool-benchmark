#!/bin/bash
source apt-package/install.sh g++
source apt-package/install.sh cmake
source apt-package/install.sh make
source git/install.sh progschj/ThreadPool.git --version 9a42ec1329f259a5f4881a291db1dcb8f2ad9040 --objs-dir "." --include-dir "." --before-linking "rm example.cpp" --alias progschj
source git/install.sh rockerbacon/parallel-tools.git --version v1.3 --alias rockerbacon
source git/install.sh rockerbacon/cpp-benchmark.git --version v1.0.5
source git/install.sh rockerbacon/stopwatch.git --version v2.1.4
source git/install.sh mtrebi/thread-pool.git --version 1c80f3abfda89afcacfb39a8e892aeb8eed0c299 --objs-dir "include" --include-dir "include" --alias mtrebi
