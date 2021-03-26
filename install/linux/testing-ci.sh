#./test # Run the test at least once to generate the .gcda file
#cd CMakeFiles/test.dir/src
#gcov testsubject.cpp.gcno
#lcov --capture --directory . --output-file gtest_coverage.info
#genhtml gtest_coverage.info --output-directory CODE_COVERAGE
#cd CODE_COVERAGE

sudo apt-get install -y lcov
cd ./build/tests
./datastructures_tests
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory CODE_COVERAGE
cd CODE_COVERAGE

#upload to CodeCov
bash <(curl -s https://codecov.io/bash) -f coverage.info -t $CODECOV_TOKEN

#https://github.com/codecov/example-cpp11-cmake
#https://github.com/hacksdump/googletest-coverage