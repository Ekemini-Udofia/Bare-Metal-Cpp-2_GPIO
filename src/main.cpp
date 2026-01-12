// Define base address for peripherals
#define PERIPH_BASE (0x40000000UL)
// Offset for AHB2 - Contains GPIOA
#define AHB2PERIHP_OFFSET (0x08000000UL)
// Base address for AHB1
#define AHB2PERIHP_BASE (PERIPH_BASE + AHB2PERIHP_OFFSET)
// Offset for GPIOA
#define GPIOA_OFFSET (0X0000UL)
// Base address for GPIOA
#define GPIOA_BASE (AHB2PERIHP_BASE + GPIOA_OFFSET)

// Offset for AHB1 - Contains RCC
#define AHB1PERIHP_OFFSET (0x00020000UL)
// Base address for AHB1
#define AHB1PERIHP_BASE (PERIPH_BASE + AHB1PERIHP_OFFSET)
// Offset for RCC
#define RCC_OFFSET (0x00001000UL)
// Base for RCC
#define RCC_BASE (AHB1PERIHP_BASE + RCC_OFFSET)

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
