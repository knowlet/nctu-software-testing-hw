[![Build Status](https://travis-ci.org/knowlet/nctu-st-hw1.svg?branch=master)](https://travis-ci.org/knowlet/nctu-st-hw1)
[![Coverage Status](https://coveralls.io/repos/github/knowlet/nctu-st-hw1/badge.svg?branch=master)](https://coveralls.io/github/knowlet/nctu-st-hw1?branch=master)


# NCTU Software Testing HW1

TDD homework using [Google Test](https://github.com/google/googletest) deployed to
[Travis-CI](https://travis-ci.org/knowlet/nctu-st-hw1) with test coverage
deployed to [Coveralls](https://coveralls.io/github/knowlet/nctu-st-hw1).

- Test-driven development
- Boundary-value analysis
- Equivalence class testing
- Edge testing
- Decision table-based testing


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
$ ./triangle_unittest

Running main() from gtest_main.cc
[==========] Running 11 tests from 4 test cases.
[----------] Global test environment set-up.
[----------] 4 tests from BoundaryValue
[ RUN      ] BoundaryValue.Normal
[       OK ] BoundaryValue.Normal (0 ms)
[ RUN      ] BoundaryValue.Robust
[       OK ] BoundaryValue.Robust (0 ms)
[ RUN      ] BoundaryValue.WorstCase
[       OK ] BoundaryValue.WorstCase (0 ms)
[ RUN      ] BoundaryValue.SpecialValue
[       OK ] BoundaryValue.SpecialValue (0 ms)
[----------] 4 tests from BoundaryValue (0 ms total)

[----------] 3 tests from EquivalenceClass
[ RUN      ] EquivalenceClass.WeakNormal
[       OK ] EquivalenceClass.WeakNormal (0 ms)
[ RUN      ] EquivalenceClass.WeakRobust
[       OK ] EquivalenceClass.WeakRobust (0 ms)
[ RUN      ] EquivalenceClass.StrongRobust
[       OK ] EquivalenceClass.StrongRobust (0 ms)
[----------] 3 tests from EquivalenceClass (0 ms total)

[----------] 3 tests from EdgeTesting
[ RUN      ] EdgeTesting.WeakNormal
[       OK ] EdgeTesting.WeakNormal (0 ms)
[ RUN      ] EdgeTesting.WeakRobust
[       OK ] EdgeTesting.WeakRobust (0 ms)
[ RUN      ] EdgeTesting.StrongRobust
[       OK ] EdgeTesting.StrongRobust (0 ms)
[----------] 3 tests from EdgeTesting (1 ms total)

[----------] 1 test from DecisionTable
[ RUN      ] DecisionTable.Based
[       OK ] DecisionTable.Based (0 ms)
[----------] 1 test from DecisionTable (0 ms total)

[----------] Global test environment tear-down
[==========] 11 tests from 4 test cases ran. (1 ms total)
[  PASSED  ] 11 tests.

```

