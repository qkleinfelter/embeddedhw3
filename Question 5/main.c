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

// Set up the port A
void initPortA(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R &= ~0x38;      // 3) disable analog on PA3, PA4, and PA5
  GPIO_PORTA_PCTL_R &= ~0x00FFF000; // 4) PCTL GPIO on PA3, PA4, and PA5
  GPIO_PORTA_DIR_R |= 0x38;        	// 5) PA3, PA4, and PA5 enabled to do output
  GPIO_PORTA_AFSEL_R &= ~0x38;      // 6) PA3, PA4, and PA5 regular port function
  GPIO_PORTA_DEN_R |= 0x38;         // 7) enable PA3, PA4, and PA5 digital port
}


int main(void){ 
  
	volatile unsigned long delay;
	// Init Port A
	initPortA();

	
	while(1){
	}
}
