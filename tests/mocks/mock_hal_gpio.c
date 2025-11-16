#include "mock_hal_gpio.h"

#include "unity.h"

// شمارنده و آخرین مقدار نوشته‌شده
int mock_writepin_called = 0;
int mock_last_value = -1;

void HAL_GPIO_WritePin(int port, int pin, int value) {
    mock_writepin_called++;
    mock_last_value = value;
}
