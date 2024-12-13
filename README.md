# C++23: handle errors and absence of values

### Value or Error : `std::expected`

A function that may produce a valid value or detect an error should return a `std:expected` type result
which contains either the expected value or an error code.

### Value or Nothing : `std::optional`

A function that may produce a valid value or no value should return a `std::optional` type result
which contains either the expected value or no value `std::nullopt`.

### Value or Error or Nothing : `std::optional<std::expected<...>>`

A function that may produce a valid value or detect an error or no value should return a `std::optional` type result which contains either the expected value or an error code or no value `std::nullopt`.

### This demo was tested with the Apple C++23 compiler

```
cpp-23-in-24 % /usr/bin/clang++ --version                                                                       [main L|✔]
Apple clang version 16.0.0 (clang-1600.0.26.6)
Target: arm64-apple-darwin24.1.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin

```

## Build, run and document

`make run` : build and run the demo

`make doxygen` : build the documentation and open it in the browser
