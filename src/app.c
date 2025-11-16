#include "app.h"

#include <stdio.h>

#ifdef UNIT_TEST
#include "mock_hal_gpio.h"
#else
#include "hal_gpio.h"
#endif

void app_init(void) { printf("app_init called\n"); }

void led_on(void) {
    HAL_GPIO_WritePin(GPIO_PORT_LED, GPIO_PIN_LED, GPIO_PIN_SET);
}
