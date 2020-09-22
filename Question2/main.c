// Program written by: Quinn Kleinfelter
// Date Created: 09/21/2020
// Last Modified: 09/21/2020
// Lab Section: 003
// Lab Instructor: Suba Sah
// Lab Project Number: HW 3
// Brief description of the program
// Negative logic switch on Port B pin 0

#include <stdint.h>
#include "C:/Keil/EECS 3100/Project Templates/inc/tm4c123gh6pm.h"

// Set up port B
void initPortB(void){ volatile unsigned long delay;

  SYSCTL_RCGC2_R |= 0x00000002;     // 1) activate clock for Port B
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
                                    // 2) no need to unlock GPIO Port B
  GPIO_PORTB_AMSEL_R &= ~0x01;      // 3) disable analog on PB0
  GPIO_PORTB_PCTL_R &= ~0x0000000F; // 4) PCTL GPIO on PB0
  GPIO_PORTB_DIR_R &= ~0x01;        // 5) direction PB0 input
  GPIO_PORTB_AFSEL_R &= ~0x01;      // 6) PB0 regular port function
	GPIO_PORTB_PUR_R = 0x01;					// 7) Enable Pull-up on PB0
  GPIO_PORTB_DEN_R |= 0x01;         // 7) enable PB0 digital port
}

// Function to read in the data on Port B pin 0
// 0x01 = 0000 0001
unsigned long Switch_Input(void){
	return (GPIO_PORTB_DATA_R&0x01); // 0x01 if not pressed or 0x00 if pressed
}

int main(void){ 
 
	volatile unsigned long test;
	// Init Port B
	initPortB();

	
	while(1){
		// While looping endlessly make the test
		// value equivalent to the switch input
		test = Switch_Input();
	}
}
