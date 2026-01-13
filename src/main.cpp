#include <src/stm32f030f4_regs.hpp>


// Bit mask for enabling GPIOA - Bit 17
#define GPIOAEN (1U << 17)
// Bit mask for GPIOA pin 4
#define PIN5 (1U << 5)

int main(void) {
  // Enable Clock Access to GPIOA
  RCC_AHBENR |= GPIOAEN;

  // Setting bit 9 of GPIOA_MODER to 0 and bit 8 to 1
  GPIOA_MODER |= (1U << 8);   // Bit 8 -> 1
  GPIOA_MODER &= ~(1U << 9);  // Bit 9 -> 0

  // Infinite loop to turn on  LED
  while (1) {
    GPIOA_ODR |= PIN5;  // Toggle pin 4
    for (int i = 0; i < 100000; ++i) {
      // Delay loop for blinking to be visible
    }
  }
}
