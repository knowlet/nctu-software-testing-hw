[![Build Status](https://travis-ci.org/knowlet/nctu-software-testing-hw.svg?branch=master)](https://travis-ci.org/knowlet/nctu-software-testing-hw)
[![Coverage Status](https://coveralls.io/repos/github/knowlet/nctu-st-hw1/badge.svg?branch=master)](https://coveralls.io/github/knowlet/nctu-st-hw1?branch=master)
[![codecov](https://codecov.io/gh/knowlet/nctu-st-hw1/branch/master/graph/badge.svg)](https://codecov.io/gh/knowlet/nctu-st-hw1)


# NCTU Software Testing

TDD homework using [Google Test](https://github.com/google/googletest) deployed to
[Travis-CI](https://travis-ci.org/knowlet/nctu-st-hw1) with test coverage
deployed to [Coveralls](https://coveralls.io/github/knowlet/nctu-st-hw1).

- Test-driven development
- Boundary-value analysis
- Equivalence class testing
- Edge testing
- Decision table-based testing
- Path testing


## How to build

```bash
git clone https://github.com/knowlet/nctu-st-hw1.git
cd nctu-st-hw1
git submodule update --init
make
```


## Running the tests

Either using `make test`:
```
$ find . -name '*_unittest' -exec {} \;
Running main() from gtest_main.cc
[==========] Running 6 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 6 tests from CommissionTest
[ RUN      ] CommissionTest.NormalBoundary
[       OK ] CommissionTest.NormalBoundary (0 ms)
[ RUN      ] CommissionTest.Equivalence
[       OK ] CommissionTest.Equivalence (0 ms)
[ RUN      ] CommissionTest.CodeCoverageC0
[       OK ] CommissionTest.CodeCoverageC0 (0 ms)
[ RUN      ] CommissionTest.CodeCoverageC1
[       OK ] CommissionTest.CodeCoverageC1 (0 ms)
[ RUN      ] CommissionTest.CodeCoverageC2
[       OK ] CommissionTest.CodeCoverageC2 (0 ms)
[ RUN      ] CommissionTest.CodeCoverageMCDC
[       OK ] CommissionTest.CodeCoverageMCDC (0 ms)
[----------] 6 tests from CommissionTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 6 tests.
Running main() from gtest_main.cc
[==========] Running 7 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from NextDateProblem
[ RUN      ] NextDateProblem.BoundaryValueNormal
[       OK ] NextDateProblem.BoundaryValueNormal (1 ms)
[ RUN      ] NextDateProblem.BoundaryValueRobust
[       OK ] NextDateProblem.BoundaryValueRobust (0 ms)
[ RUN      ] NextDateProblem.BoundaryValueSpecialValue
[       OK ] NextDateProblem.BoundaryValueSpecialValue (0 ms)
[----------] 3 tests from NextDateProblem (1 ms total)

[----------] 4 tests from NextDateTest
[ RUN      ] NextDateTest.CodeCoverageC0
[       OK ] NextDateTest.CodeCoverageC0 (0 ms)
[ RUN      ] NextDateTest.CodeCoverageC1
[       OK ] NextDateTest.CodeCoverageC1 (0 ms)
[ RUN      ] NextDateTest.CodeCoverageC2
[       OK ] NextDateTest.CodeCoverageC2 (0 ms)
[ RUN      ] NextDateTest.CodeCoverageMCDC
[       OK ] NextDateTest.CodeCoverageMCDC (0 ms)
[----------] 4 tests from NextDateTest (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 7 tests.
Running main() from gtest_main.cc
[==========] Running 16 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 16 tests from TriangleTest
[ RUN      ] TriangleTest.BoundaryValueNormal
[       OK ] TriangleTest.BoundaryValueNormal (0 ms)
[ RUN      ] TriangleTest.BoundaryValueRobust
[       OK ] TriangleTest.BoundaryValueRobust (0 ms)
[ RUN      ] TriangleTest.BoundaryValueWorstCase
[       OK ] TriangleTest.BoundaryValueWorstCase (0 ms)
[ RUN      ] TriangleTest.BoundaryValueSpecialValue
[       OK ] TriangleTest.BoundaryValueSpecialValue (0 ms)
[ RUN      ] TriangleTest.EquivalenceClassWeakNormal
[       OK ] TriangleTest.EquivalenceClassWeakNormal (0 ms)
[ RUN      ] TriangleTest.EquivalenceClassWeakRobust
[       OK ] TriangleTest.EquivalenceClassWeakRobust (0 ms)
[ RUN      ] TriangleTest.EquivalenceClassStrongRobust
[       OK ] TriangleTest.EquivalenceClassStrongRobust (1 ms)
[ RUN      ] TriangleTest.EdgeTestingWeakNormal
[       OK ] TriangleTest.EdgeTestingWeakNormal (0 ms)
[ RUN      ] TriangleTest.EdgeTestingWeakRobust
[       OK ] TriangleTest.EdgeTestingWeakRobust (0 ms)
[ RUN      ] TriangleTest.EdgeTestingStrongRobust
[       OK ] TriangleTest.EdgeTestingStrongRobust (0 ms)
[ RUN      ] TriangleTest.DecisionTableBased
[       OK ] TriangleTest.DecisionTableBased (0 ms)
[ RUN      ] TriangleTest.ExceptionTest
[       OK ] TriangleTest.ExceptionTest (0 ms)
[ RUN      ] TriangleTest.CodeCoverageC0
[       OK ] TriangleTest.CodeCoverageC0 (0 ms)
[ RUN      ] TriangleTest.CodeCoverageC1
[       OK ] TriangleTest.CodeCoverageC1 (0 ms)
[ RUN      ] TriangleTest.CodeCoverageC2
[       OK ] TriangleTest.CodeCoverageC2 (0 ms)
[ RUN      ] TriangleTest.CodeCoverageMCDC
[       OK ] TriangleTest.CodeCoverageMCDC (0 ms)
[----------] 16 tests from TriangleTest (1 ms total)

[----------] Global test environment tear-down
[==========] 16 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 16 tests.

```

