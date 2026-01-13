#include <gpio.hpp>

// Bit mask for enabling GPIOA - Bit 17
#define GPIOAEN (1U << 17)
// Bit mask for GPIOA pin 4
#define PIN5 (1U << 5)

#define LED_BS5 (1U << 5) // Bit Set Pin 5
#define LED_BR5 (1U << 21) // Bit Reset Pin 5

void led_init(void) {
    // Enable clocl access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;
    // Set PA5 to Output Mode
    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER &= ~(1U << 11);
}

void led_on(void) {
    // Set PA5 to high
    GPIOA->BSRR |= LED_BS5;
}

void led_off(void) {
    // Set PA5 to low
    GPIOA->BSRR |= LED_BR5;
}
