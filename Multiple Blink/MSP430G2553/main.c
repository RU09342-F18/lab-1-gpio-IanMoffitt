#include <msp430.h> 
/**
 * This is the second assignment, Multiple Blink
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//Want to make multiple LEDs blink at different rates
	//The first LEDs period is going to be about 1 second
	//The second LEDs period is going to be about 1/2 a second
	//First my PINS need to be set to GPIO LEDs
	//Same code as SIMPLE Blink but for both bits that control the LEDs (P1.0 and P1.6)

	//Set Pin 1 to a I/O
	P1SEL = 0x00;

	//Set the direction to send out on only pins that control the LEDs
	P1DIR |= 0b01000001;

	//Set the state of the output register to low
	//This means both of the LEDs will be off
	P1OUT = 0x00;

	//An Infinite while loop that will control the state of the LEDs in one full cycle
	while (1)
	{
	    //This line of toggles the state of both the LEDs
	    P1OUT ^= 0x41;

	    //Delay the cycle by 1/4 of a second
	    __delay_cycles(250000);

	    //Toggles the second LED to turn it off
	    P1OUT ^= 0x40;

	    //Delay the cycle by 1/4 of a second
	    __delay_cycles(250000);
	}

	
	return 0;
}
