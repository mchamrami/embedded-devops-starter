# Embedded DevOps Starter – STM32F401

This repository is a small, end-to-end example of bringing modern DevOps practices to bare-metal embedded development on an STM32F401 microcontroller.

The goal of the project is to show how to:
- build firmware reproducibly with **CMake + Ninja** and **arm-none-eabi-gcc**
- run **unit tests** for embedded C code
- simulate the firmware on a **virtual STM32F4-Discovery** board using **QEMU (xPack GNU Arm Eclipse QEMU)**
- collect **code coverage** reports with **lcov/gcov**
- automate everything through **GitHub Actions** on every push and pull request

## What the CI pipeline does

On each commit to `main` (or pull request), GitHub Actions will:

1. **Checkout the repository**
2. **Install the ARM GCC toolchain**
3. **Configure and build** the firmware with CMake/Ninja  
   - Target MCU: STM32F401  
   - Output: `build/firmware.elf` and `build/firmware.bin`
4. (Optional) **Run unit tests** and collect coverage data
5. **Run the firmware in QEMU** using a virtual STM32F4-Discovery board
6. **Upload artifacts** (firmware binaries and coverage HTML report) so they can be downloaded from the Actions page

This setup provides a minimal “starter template” for embedded teams who want to:
- keep firmware builds reproducible,
- run automated tests on every change,
- and get quick feedback via simulation and coverage, without needing physical hardware connected to the CI server.



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
