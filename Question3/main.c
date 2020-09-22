// Program written by: Quinn Kleinfelter
// Date Created: 09/22/2020
// Last Modified: 09/22/2020
// Lab Section: 003
// Lab Instructor: Suba Sah
// Lab Project Number: HW 3
// Brief description of the program
// Hardware connections


#include <stdint.h>
#include "C:/Keil/EECS 3100/Project Templates/inc/tm4c123gh6pm.h"

unsigned long status;

// Set up the port C
void initPortC(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000004;     // 1) activate clock for Port C
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTC_AMSEL_R &= ~0x40;      // 3) disable analog on PC6
  GPIO_PORTC_PCTL_R &= ~0x0F000000; // 4) PCTL GPIO on PC6
  GPIO_PORTC_DIR_R = 0x40;        	// 5) PC6 enabled to do output
  GPIO_PORTC_AFSEL_R &= ~0x40;      // 6) PC6 regular port function
  GPIO_PORTC_DEN_R |= 0x40;         // 7) enable PC6 digital port
}

// Make PC6 high to turn on the LED
void LED_On(void) {
	GPIO_PORTC_DATA_R = 0x40;
}

int main(void){ 
  
	volatile unsigned long delay;
	// Init Port C
	initPortC();
	LED_On();

	
	while(1){
	}
}
