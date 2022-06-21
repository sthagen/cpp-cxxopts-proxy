# cpp-cxxopts-proxy

Experimental third party proxy of jarro2783/cxxopts.

## Usage

Generate build files:

```console
❯ cmake -S . -B build
# ...
```

Build:

```console
❯ cmake --build build
[ 25%] Building CXX object CMakeFiles/cxxopts_test.dir/main.cpp.o
[ 50%] Linking CXX executable cxxopts_test
[ 50%] Built target cxxopts_test
[ 75%] Building CXX object examples/CMakeFiles/basic.dir/basic.cpp.o
[100%] Linking CXX executable basic
[100%] Built target basic
```

Execute test:

```console
❯ build/cxxopts_test
[doctest] doctest version is "2.4.4"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 3 | 3 passed | 0 failed | 0 skipped
[doctest] assertions: 0 | 0 passed | 0 failed |
[doctest] Status: SUCCESS!
```

Execute basic example:

```console
❯ build/examples/basic -h
One line description of the commandline app
Usage:
  App [OPTION...]

  -h, --help      Show help
  -d, --debug     Enable debugging
  -f, --file arg  File name
```

... or:

```console
❯ build/examples/basic -d -f value
option: debug: true
option: file: value
```
## Status

Experimental.

**Note**: The default branch is `default`.
