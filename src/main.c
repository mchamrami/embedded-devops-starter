#include "stm32f4xx.h"

int main(void)
{
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    GPIOD_MODER &= ~(3U << (PD14 * 2));
    GPIOD_MODER |=  (1U << (PD14 * 2));   // 01b

    GPIOD_OTYPER &= ~(1U << PD14);
    GPIOD_PUPDR  &= ~(3U << (PD14 * 2));

    GPIOD_BSRR = (1U << PD14);

}
