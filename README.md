[![Copier](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/copier-org/copier/master/img/badge/badge-grayscale-inverted-border-orange.json)](https://github.com/copier-org/copier)

# bitpacking

Small library to pack 8 bits into 6.

## CMake

The project has been initialized with a [CMakeLists.txt](CMakeLists.txt)-based
configuration for building with CMake:

```shell
# change into the build directory
cd build/cmake

# generate the build files
cmake ../..

# build the project
cmake --build .

# install the project to <repo>/build/cmake/dist
cmake --install .

# run the program to see if it works
./dist/bin/pack
```

Should output something like:

```text
unpacked[0] = 32
unpacked[1] = 24
unpacked[2] = 6
unpacked[3] = 1
packed[0] = 0
packed[1] = 0
packed[2] = 0

unpacked[0] = 32
unpacked[1] = 24
unpacked[2] = 6
unpacked[3] = 1
packed[0] = 129
packed[1] = 129
packed[2] = 129

resetting unpacked
unpacked[0] = 0
unpacked[1] = 0
unpacked[2] = 0
unpacked[3] = 0
packed[0] = 129
packed[1] = 129
packed[2] = 129

unpacked[0] = 32
unpacked[1] = 24
unpacked[2] = 6
unpacked[3] = 1
packed[0] = 129
packed[1] = 129
packed[2] = 129
```

## Testing

The tests require that [Criterion](https://github.com/Snaipe/Criterion) is installed on the system, e.g. with

```shell
sudo apt install libcriterion-dev
```

Run the tests with

```shell
./dist/bin/test_bitpacking -j1 --verbose
```

## `clang-format`

The file `.clang-format` contains an initial configuration for (automatic) formatting with [clang-format](https://clang.llvm.org/docs/ClangFormat.html). Run the formatter with e.g.:

```shell
# dry run on main.c
clang-format -Werror --dry-run main.c

# format in place all *.c and *.h files under ./src
clang-format -i `find ./src -type f -name '*.[c|h]'`
```

## Acknowledgements

_This project was generated using [Copier](https://pypi.org/project/copier) and the [Copier template for c projects](https://github.com/jspaaks/copier-template-for-c-projects)._
