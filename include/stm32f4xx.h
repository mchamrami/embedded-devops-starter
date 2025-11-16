#ifndef STM32F4XX_H
#define STM32F4XX_H

#include <stdint.h>

/* ---------- RCC ---------- */
#define PERIPH_BASE          (0x40000000UL)
#define AHB1PERIPH_BASE      (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE             (AHB1PERIPH_BASE + 0x3800UL)

#define RCC_AHB1ENR          (*(volatile uint32_t *)(RCC_BASE + 0x30UL))
/* بیت 3 ساعت GPIOD است */
#define RCC_AHB1ENR_GPIODEN  (1U << 3)

/* ---------- GPIOD ---------- */
#define GPIOD_BASE           (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOD_MODER          (*(volatile uint32_t *)(GPIOD_BASE + 0x00UL))
#define GPIOD_OTYPER         (*(volatile uint32_t *)(GPIOD_BASE + 0x04UL))
#define GPIOD_OSPEEDR        (*(volatile uint32_t *)(GPIOD_BASE + 0x08UL))
#define GPIOD_PUPDR          (*(volatile uint32_t *)(GPIOD_BASE + 0x0CUL))
#define GPIOD_IDR            (*(volatile uint32_t *)(GPIOD_BASE + 0x10UL))
#define GPIOD_ODR            (*(volatile uint32_t *)(GPIOD_BASE + 0x14UL))
#define GPIOD_BSRR           (*(volatile uint32_t *)(GPIOD_BASE + 0x18UL))

/* کمک‌ثابت‌ها برای PD14 */
#define PD14                 14U
#define GPIO_MODE_OUTPUT     1U    /* 01b */

#endif /* STM32F4XX_H */
