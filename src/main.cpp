#include <gpio.hpp>


int main(void) {
  // Initialize LED
  led_init();
  while (1) {
    // Turn LED on
    led_on();
    // Delay
    for (int i = 0; i < 1000000; ++i) {}
    // Turn LED off
    led_off();
    for (int i = 0; i < 1000000; ++i) {}
  }
}
