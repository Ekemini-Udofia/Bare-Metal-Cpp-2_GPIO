#include <gpio_input_driver.hpp>

#define GPIOBEN (1U << 18)
#define PIN3 (1U << 3)
#define BTN_PIN PIN3

void btn_init(void) {
  // Enable Port B
  RCC->AHB1ENR |= GPIOBEN;

  // Set Moder for pin 3 to intput mode (bit 6 = 0, 7 = 0)
  GPIOB->MODER &= ~(1U << 6);
  GPIOB->MODER &= ~(1U << 7);
}

bool get_button_state(void) {
  if (GPIOB->IDR & BTN_PIN) {
    return false;
  } else {
    return true;
  }
}
