#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#define GPIO_PORT_LED 0
#define GPIO_PIN_LED 13

#define GPIO_PIN_RESET 0
#define GPIO_PIN_SET 1

void HAL_GPIO_WritePin(int port, int pin, int value);

#endif  // HAL_GPIO_H
