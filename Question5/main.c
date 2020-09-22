// Program written by: Quinn Kleinfelter
// Date Created: 09/22/2020
// Last Modified: 09/22/2020
// Lab Section: 003
// Lab Instructor: Suba Sah
// Lab Project Number: HW 3
// Brief description of the program
// Outputs a value between 0x00 and 0x07
// to the Pins 3, 4, and 5 on Port A


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

// Write the value from inp to PA3, PA4, and PA5
void writeToPins(unsigned char inp) {
	if (inp > 0x07) {
		return; // We only want to write in the range 0x00-0x07
	}
	// We need to left shift the input so that they are correctly moved
	// to the 3 bits we use, PA3, PA4, and PA5
	GPIO_PORTA_DATA_R = (inp << 3);
}

int main(void){ 
  
	volatile unsigned long delay;
	// Init Port A
	initPortA();

	// Write all applicable values to the pins for testing
	writeToPins(0x00);
	writeToPins(0x01);
	writeToPins(0x02);
	writeToPins(0x03);
	writeToPins(0x04);
	writeToPins(0x05);
	writeToPins(0x06);
	writeToPins(0x07);
	
	while(1){
	}
}
