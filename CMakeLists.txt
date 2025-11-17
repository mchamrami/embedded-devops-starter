cmake_minimum_required(VERSION 3.21)


project(embedded_devops LANGUAGES C ASM)
set(CMAKE_C_STANDARD 11)

# 
option(ENABLE_CODE_COVERAGE "Enable coverage on host builds" OFF)
if(DEFINED ENV{GITHUB_ACTIONS} AND NOT CMAKE_C_COMPILER MATCHES "arm-none-eabi")
  message(STATUS "✅ GitHub Actions (host build): enabling coverage")
  add_compile_options(--coverage)
  add_link_options(--coverage)
  set(ENABLE_CODE_COVERAGE ON)
endif()

#
set(IS_ARM FALSE)
if(CMAKE_C_COMPILER MATCHES "arm-none-eabi")
  set(IS_ARM TRUE)
endif()

# ============ Firmware (ARM) ============
if(IS_ARM)
  add_executable(firmware.elf
    startup/startup_stm32f401xc.s
    src/main.c
    src/app.c
    src/hal_gpio.c
    src/syscalls.c
    src/system_stm32f4xx.c
  )

  # 
  target_include_directories(firmware.elf PRIVATE include)

  # 
  target_compile_options(firmware.elf PRIVATE
    -mcpu=cortex-m4 -mthumb
    -ffunction-sections -fdata-sections
    -O2 -Wall
  )

  # 
  target_link_options(firmware.elf PRIVATE
    -T${CMAKE_SOURCE_DIR}/STM32F401_FLASH.ld
    -Wl,--gc-sections
    --specs=nano.specs
    --specs=nosys.specs
    -nostartfiles
  )

  # 
  add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware.elf> firmware.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:firmware.elf>
  )
endif()

# ============ Tests  ============
enable_testing()

# ت
if(NOT IS_ARM)
  add_subdirectory(tests)
endif()
