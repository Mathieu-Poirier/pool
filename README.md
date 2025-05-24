# Dependencies

This project uses the following dependencies and tools:

## Core Tools

- **C++20** — Core language standard
- **CMake** (≥ 3.16) — Cross-platform build system
- **Conan** (v2) — C++ package manager
- **GCC or Clang** — Modern C++ compiler

## Conan Packages

```ini
[requires]
gtest/1.14.0

[generators]
cmake

[options]
gtest:shared=False
```

## License

This project is licensed under the [MIT License](./LICENSE).
