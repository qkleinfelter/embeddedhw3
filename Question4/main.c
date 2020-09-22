// Program written by: Quinn Kleinfelter
// Date Created: 09/22/2020
// Last Modified: 09/22/2020
// Lab Section: 003
// Lab Instructor: Suba Sah
// Lab Project Number: HW 3
// Brief description of the program
// Negative logic LED on Port D pin 3
// note: the assignment says use pin 4, but
// it is unavailable due to the usb header
// so pin 3 was used

#include <stdint.h>
#include "C:/Keil/EECS 3100/Project Templates/inc/tm4c123gh6pm.h"

// Set up the port D
void initPortD(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000008;     // 1) activate clock for Port D
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTD_AMSEL_R &= ~0x08;      // 3) disable analog on PD3
  GPIO_PORTD_PCTL_R &= ~0x0000F000; // 4) PCTL GPIO on PD3
  GPIO_PORTD_DIR_R = 0x08;        	// 5) PD3 enabled to do output
  GPIO_PORTD_AFSEL_R &= ~0x08;      // 6) PD3 regular port function
  GPIO_PORTD_DEN_R |= 0x08;         // 7) enable PD3 digital port
}

// Make PD3 high to turn off the LED
void LED_Off(void) {
	GPIO_PORTD_DATA_R = 0x08;
}

int main(void){ 
	
	// Init Port D
	initPortD();
	// and turn off the LED
	LED_Off();

	
	while(1){
	}
}
