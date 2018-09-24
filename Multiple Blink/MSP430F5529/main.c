#include <msp430.h> 
/**
 * This is the second assignment, Multiple Blink
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //This code is almost identical to the Multiple Blink assignment for the MSP430G3553
    //The main difference is that the location for LED2 is Port 4 bit 7

    //Want to make multiple LEDs blink at different rates
    //The first LEDs period is going to be about 1 second
    //The second LEDs period is going to be about 1/2 a second
    //First my PINS need to be set to GPIO LEDs
    //Same code as SIMPLE Blink but for both bits that control the LEDs (P1.0 and P4.7)

    //Set Pin 1 to a I/O
    P1SEL = 0x00;
    //Set Pin 4 to a I/O
    P4SEL = 0x00;

    //Set the direction to send out on only pins that control the LED in Port 1
    P1DIR |= 0x01;
    //Set the direction to send out data to the pins that control the LED in port 4
    P4DIR |= 0x80;


    //Set the state of the output register to low
    //This means both of the LEDs will be off
    P1OUT = 0x00;
    P4OUT = 0x00;

    //An Infinite while loop that will control the state of the LEDs in one full cycle
    while (1)
    {
        //This line of toggles the state of both the LEDs
        P1OUT ^= 0x01;
        P4OUT ^= 0x80;

        //Delay the cycle by 1/4 of a second
        __delay_cycles(250000);

        //Toggles the second LED to turn it off
        P4OUT ^= 0x80;

        //Delay the cycle by 1/4 of a second
        __delay_cycles(250000);
    }


    return 0;
}
