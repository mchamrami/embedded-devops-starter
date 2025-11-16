# Toolchain for ARM (STM32)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# جلوگیری از لینک در تست تشخیص کامپایلر
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

# فلگ‌های کامپایل عمومی
set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb")
set(COMMON_C_FLAGS "-ffunction-sections -fdata-sections -Wall -O2")
set(CMAKE_C_FLAGS "${CPU_FLAGS} ${COMMON_C_FLAGS}")

# فلگ‌های لینک عمومی (بدون -T؛ اسکریپت لینک را فقط روی تارگت ست می‌کنیم)
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections --specs=nosys.specs --specs=nano.specs -nostartfiles")
