#!/bin/bash

# INSTALL TESTING DEPENDENCY
git clone https://github.com/google/googletest.git -b release-1.10.0
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install

#INSTALL CODE COVERAGE DEPENDENCY
sudo apt-get install -y lcov
