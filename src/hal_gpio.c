#include "hal_gpio.h"

#include <stdio.h>

void HAL_GPIO_WritePin(int port, int pin, int value) {
    (void)port;
    (void)pin;
    (void)value;

    /* Placeholder implementation: in production this should drive hardware. */
#ifdef DEBUG
    printf("HAL_GPIO_WritePin(port=%d, pin=%d, value=%d)\n", port, pin, value);
#endif
}
