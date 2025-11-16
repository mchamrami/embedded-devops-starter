#include "app.h"
#include "mock_hal_gpio.h"
#include "unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_led_on_should_call_HAL_GPIO_WritePin(void) {
    mock_writepin_called = 0;
    mock_last_value = 0;

    led_on();  // از app.c فراخوانی میشه

    TEST_ASSERT_EQUAL_INT(1, mock_writepin_called);
    TEST_ASSERT_EQUAL_INT(GPIO_PIN_SET, mock_last_value);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_led_on_should_call_HAL_GPIO_WritePin);
    return UNITY_END();
}
