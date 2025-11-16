#include "stm32f4xx.h"

int main(void)
{
    /* 1) فعال‌سازی کلاک GPIOD */
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    /* 2) PD14 خروجی */
    GPIOD_MODER &= ~(3U << (PD14 * 2));
    GPIOD_MODER |=  (1U << (PD14 * 2));   // 01b

    /* 3) Push-Pull و بدون Pull */
    GPIOD_OTYPER &= ~(1U << PD14);
    GPIOD_PUPDR  &= ~(3U << (PD14 * 2));

    /* 4) روشن کردن LED روی PD14 */
    GPIOD_BSRR = (1U << PD14);

   // while (1) { __asm volatile ("nop"); }
}
