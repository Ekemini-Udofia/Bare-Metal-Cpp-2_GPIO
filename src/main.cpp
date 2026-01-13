#include <Headers.hpp>


int main(void) {
  // Initialize LED and button on PB3
  led_init();
  btn_init();

  bool button_state;

  while (1) {
    button_state = get_button_state();
    if (button_state) {
        led_on();
    } else {
        led_off();
    }
  }
}
