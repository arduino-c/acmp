ACMP
====

Analog Comparator driver for Arduino Uno

###Usage

* Write your code, e.g. in *main.c*

```c
...
#include "init.h"
#include <acmp.h>

int main() {
  init();
  
  sei(); /* enable global interrupts */

  while(1) {
  	while(acmp_triggered); /* wait for acmp trigger */
  	
  	...
  }
  
  return 0;
}
```
