#include <msp430.h> 
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//Access the register/memory associated with the LED at D1 and D2
	//This is the Port1 output bit 0 and bit 6 respectively

	//Configure the port with the LEDs to be a GPIO port

	//Set Port1 to I/O instead of Peripheral (1)
	P1SEL = 0x00;
	//Set direction of Port1 I/O to Out
	P1DIR = 1;

	//Since the Green LED is bit 0 of the Port1 set of pins, need to adjust 0000000*0*
	//Set Green to be logic low (off)
	P1OUT = 0x00;

	//A PHAT Infinite loop where the cycle
	while (1)
	{
	    //Invert the state of the LED at P1.O
	    P1OUT ^= 0b00000001;

	    //Delay the program by 500000 clock cycles (about half a second)
	    __delay_cycles(500000);

	    //Restart the while loop where the state is inverted again
	    //This timing gives the period of the LED ~1sec
	}

	return 0;
}
