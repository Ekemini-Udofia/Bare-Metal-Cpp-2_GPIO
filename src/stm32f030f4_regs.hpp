#include <cstdint>

typedef struct {
  volatile uint32_t MODER;    // 0x00
  volatile uint32_t OTYPER;   // 0x04
  volatile uint32_t OSPEEDR;  // 0x08
  volatile uint32_t PUDPR;    // 0x0C
  volatile uint32_t IDR;      // 0x10
  volatile uint32_t ODR;      // 0x14
  volatile uint32_t BSRR;     // 0x18
  volatile uint32_t LCKR;     // 0x1C
  volatile uint32_t AFRL;     // 0x20
  volatile uint32_t AFR;      // 0x24
  volatile uint32_t BRR;      // 0x28
} GPIO_TypeDef;

typedef struct {
  volatile uint32_t Dummy_space[12];
  volatile uint32_t AHB1ENR;
} RCC_TypeDef;

#define RCC_BASE 0x40021000UL
#define GPIOA_BASE 0x48000000ul
#define GPIOB_BASE 0x48000400ul

#define RCC ((RCC_TypeDef *)RCC_BASE)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)

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
