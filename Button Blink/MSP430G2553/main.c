#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//This project is designed to poll for inputs from the user at the PBNO and then toggle the switch
	//a variable that will hold the value of the P1IN in the location of the button
	int input;

	//First set the Port 1 to be IO
	P1SEL = 0x00;

	//Set the direction of Port 1 to be input for button without damaging contents of the register
	P1DIR &= 0xF7;

	//Set the direction of Port 1 to be the output for the LED
	P1DIR |= 0x01;

	//infinite loop where program runs
	while (1)
	{
	    //Sets the state of the LED to Off
	    P1OUT = 0x00;

	    //Take the input from the button and take out only the bit for the button
	    input = P1IN & 0x08;

	    //Enter and stay in a loop if the input is read as on
	    //It is does not equal due to when testing the loop would enter when the button was not pressed
	    //This led me to believe that the Push button is a Push button normally closed (On by default)
	    //So the loop will now be entered when the button is clicked
	    while(input != 0x08)
	    {
	        P1OUT = 0x01;
	        input = P1IN & 0x08;
	    }

	}
	
	return 0;
}
