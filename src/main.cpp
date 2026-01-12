#include <src/stm32f030f4_regs.hpp>

// Define AHBENR offset
#define RCC_AHBENR_OFFSET (0x14UL)
// Define AHBENR address
#define RCC_AHBENR                       \
  (*(volatile unsigned int *)(RCC_BASE + \
                              RCC_AHBENR_OFFSET))  // GPIOA_EN is on bit 17

// Define GPIOA_MODER offset
#define MODER_OFFSET (0x0000UL)
// Define GPIOA_MODER
#define GPIOA_MODER (*(volatile unsigned int *)(GPIOA_BASE + MODER_OFFSET))

// Offset for the output data register
#define ODR_OFFSET (0x14UL)
// Address for GPIOA_ODR
#define GPIOA_ODR (*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))

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
