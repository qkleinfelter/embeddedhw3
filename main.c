// Program written by: Quinn Kleinfelter
// Date Created: 09/21/2020
// Last Modified: 09/21/2020
// Lab Section: 003
// Lab Instructor: Suba Sah
// Lab Project Number: HW 3
// Brief description of the program
// Hardware connections
// The specific operation of this system is to 
//   unlock if all three switches are pressed

#include <stdint.h>
#include "C:/Keil/EECS 3100/Project Templates/inc/tm4c123gh6pm.h"

unsigned long status;

// Set up the port A
void initPortA(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) A clock
  delay = SYSCTL_RCGC2_R;           // delay
  GPIO_PORTE_AMSEL_R = 0x00;        // Disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // Clear PCTL
  GPIO_PORTE_DIR_R = 0x80;          // PA7 as input
  GPIO_PORTE_AFSEL_R = 0x00;        // no alternate function
  GPIO_PORTE_PUR_R = 0x80;          // Enable Pull up resistor on PA7
  GPIO_PORTE_DEN_R = 0x80;          // Digital Enable I/O on PA7
}

int main(void){ 
  
	volatile unsigned long delay;
	// Init Port A
	initPortA();
	
	while(1){

	}
}
