#!/bin/bash
source apt-package/install.sh cmake
source apt-package/install.sh make
source apt-package/install.sh g++
source git/install.sh progschj/ThreadPool --objs-dir '.' --include-dir '.' --before-linking '' --alias 'progschj' --version 9a42ec1329f259a5f4881a291db1dcb8f2ad9040
source git/install.sh rockerbacon/parallel-tools --alias 'rockerbacon' --version v1.3
source git/install.sh rockerbacon/cpp-benchmark --version v1.0.5
source git/install.sh rockerbacon/stopwatch --version v2.1.4
source git/install.sh mtrebi/thread-pool --objs-dir 'include' --include-dir 'include' --alias 'mtrebi' --version 1c80f3abfda89afcacfb39a8e892aeb8eed0c299
