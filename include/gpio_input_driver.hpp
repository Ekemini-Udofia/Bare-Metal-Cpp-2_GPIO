#ifndef INC_GPIO_INPUT_DRIVER_HPP_
#define INC_GPIO_INPUT_DRIVER_HPP_

#include <stm32f030f4_regs.hpp>

void btn_init(void);
bool get_button_state(void);


#endif // INC_GPIO_INPUT_DRIVER_HPP_
