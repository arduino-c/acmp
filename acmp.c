
#include <avr/io.h>
#include <avr/interrupt.h>

int volatile acmp_triggered;

/*
 * SETUP: AIN0: (+), AIN1: (-)
 * WARNING: after init need sei()
 */
void acmp_init() {
  ADCSRB = 0;
  ACSR = _BV(ACIE)/*en Int*/ | _BV(ACIS1) | _BV(ACIS0);/*Int on rising out edge*/
  DIDR1 = _BV(AIN1D) | _BV(AIN1D); /* disable digital circuits on AIN0 & AIN1 */
}


ISR(ANALOG_COMP_vec) {
  acmp_triggered = 1;
}
