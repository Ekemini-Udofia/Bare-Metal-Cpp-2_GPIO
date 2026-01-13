#ifndef INC_GPIO_OUTPUT_DRIVER_HPP_
#define INC_GPIO_OUTPUT_DRIVER_HPP_

#include <stm32f030f4_regs.hpp>

void led_init(void);
void led_on(void);
void led_off(void);

#endif  // INC_GPIO_OUTPUT_DRIVER_HPP_
