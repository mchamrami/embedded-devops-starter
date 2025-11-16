# Embedded DevOps Starter

[![Build Status](https://github.com/keiraward/embedded-devops-starter/actions/workflows/ci.yml/badge.svg)](https://github.com/keiraward/embedded-devops-starter/actions)

## Code coverage

The CI workflow collects coverage information using `lcov`/`gcov` and publishes
an HTML report as an artifact. You can reproduce the same report locally with
the following commands:

```sh
cmake -S . -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DENABLE_CODE_COVERAGE=ON
cmake --build build
cd build && ctest --output-on-failure
lcov --gcov-tool gcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
```

The workflow also invokes `gcovr` to emit a textual summary in the CI logs and
to generate XML/HTML artifacts that can be consumed by other tooling.
