#!/bin/bash
apt-package/install.sh g++
apt-package/install.sh cmake
apt-package/install.sh make
git/install.sh https://github.com/rockerbacon/cpp-benchmark.git v1.0.1 false "src/objs" "src/objs"
git/install.sh https://github.com/rockerbacon/parallel-tools.git v1.0 false "src/objs" "src/objs"
git/install.sh https://github.com/progschj/ThreadPool.git 9a42ec1329f259a5f4881a291db1dcb8f2ad9040 false "." "." "rm example.cpp"
