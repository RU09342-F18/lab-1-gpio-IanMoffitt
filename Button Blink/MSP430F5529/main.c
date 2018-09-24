#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //This code is almost identical to the code used for the MSP430G2553
    //The difference is the location of the PBNC on the MSP430F5529 is at 1.1 and the push button is a push button normally open

    //This project is designed to poll for inputs from the user at the PBNO and then toggle the switch
    //a variable that will hold the value of the P1IN in the location of the button
    int input;

    //First set the Port 1 to be IO
    P1SEL = 0x00;

    //Set the direction of Port 1 to be input for button without damaging contents of the register
    P1DIR &= 0xF2;

    //Set the initial value of the LED to Off
    P1OUT = 0x00;

    //Set the direction of Port 1 to be the output for the LED
    P1DIR |= 0x01;


    //infinite loop where program runs
    while (1)
    {
        //Sets the state of the LED to Off
        P1OUT = 0x00;

        //Take the input from the button and take out only the bit for the button
        input = P1IN & 0x02;

        //Unlike the MSP430G2553 this button is a PBNO (off by default)
        //So the loop will now be entered when the button is clicked
        while(input == 0x02)
        {
            P1OUT = 0x01;
            input = P1IN & 0x02;
        }

    }

    return 0;
}
