[![Build Status](https://travis-ci.org/arsenygolubtsov/tree-2.svg?branch=master)](https://travis-ci.org/arsenygolubtsov/tree-2)
```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
