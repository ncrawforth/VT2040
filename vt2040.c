#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "lcd.h"
#include "term.h"
#include "serial.h"
#include "keyb.h"
#include "splash.h"

int main() {
  // Initialise serial port
  serial_init();

  // Initialise LCD screen driver
  lcd_init();
  
  // Initialise terminal
  term_init();

  // Draw splash screen
  for (int i = 0; i < splash_len; i++) term_putc(splash[i]);
  lcd_invalidate();
  
  // Initialise keyboard
  keyb_init();
  
  // Run
  while (1) {
    if (serial_ready()) {
      while (serial_ready()) {
        serial_puts(term_putc(serial_getc()));
      }
      lcd_invalidate();
    }

    int32_t keycode = keyb_scan();
    switch (keycode) {
      case 0:
        break;
      case KEYB_KC_INVERT:
        lcd_invert();
        break;
      case KEYB_KC_ROTATE:
        lcd_rotate();
        break;
      case KEYB_KC_DARKEN:
        lcd_darken();
        break;
      case KEYB_KC_BRIGHTEN:
        lcd_brighten();
        break;
      default:
        serial_puts(term_keypress(keycode));
    }
    sleep_ms(1);
  }
}
