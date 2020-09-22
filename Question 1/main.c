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

#define PA7   (*((volatile unsigned long *)0x40004200))

unsigned long status;

// Set up the port A
void initPortA(void){ volatile unsigned long delay;

  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
                                    // 2) no need to unlock GPIO Port A
  GPIO_PORTA_AMSEL_R &= ~0x80;      // 3) disable analog on PA7
  GPIO_PORTA_PCTL_R &= ~0xF0000000; // 4) PCTL GPIO on PA7
  GPIO_PORTA_DIR_R &= ~0x80;        // 5) direction PA7 input
  GPIO_PORTA_AFSEL_R &= ~0x80;      // 6) PA7 regular port function
  GPIO_PORTA_DEN_R |= 0x80;         // 7) enable PA7 digital port
}

unsigned long Switch_Input(void){
	return PA7;
}

unsigned long Switch_Input2(void){
	return (GPIO_PORTA_DATA_R&0x80);
}

int main(void){ 
  
	volatile unsigned long delay;
	volatile unsigned long test;
	// Init Port A
	initPortA();

	
	while(1){
		test = Switch_Input();
		test = Switch_Input2();
	}
}
