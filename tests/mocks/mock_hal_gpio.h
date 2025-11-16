#pragma once
#ifndef MOCK_HAL_GPIO_H
#define MOCK_HAL_GPIO_H

// تعریف‌های جعلی فقط برای تست
#define GPIO_PORT_LED 1
#define GPIO_PIN_LED 13

#define GPIO_PIN_RESET 0
#define GPIO_PIN_SET 1

// Prototype تابع HAL اصلی
void HAL_GPIO_WritePin(int port, int pin, int value);

// متغیرهای مانیتورینگ برای تست
extern int mock_writepin_called;
extern int mock_last_value;

#endif
