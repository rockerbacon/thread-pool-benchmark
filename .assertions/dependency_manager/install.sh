#!/bin/bash
apt-package/install.sh g++
apt-package/install.sh cmake
apt-package/install.sh make
systemlib/install.sh pthread
git/install.sh https://github.com/rockerbacon/cpp-benchmark.git 004a9ffdf98b350c45030e4240d8694953e880a0
git/install.sh https://github.com/rockerbacon/stopwatch.git v2.0
git/install.sh https://github.com/rockerbacon/parallel-tools.git 5387334123192bd608a425f4d0db0be7c4a9ede8
