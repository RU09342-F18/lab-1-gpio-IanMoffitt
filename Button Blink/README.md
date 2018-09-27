# Button Blink Read Me
The button blink program can be broken down into two steps. First by setting the correct pins to be input for the button and output for the LED. This is done is the exact same matter as the last two sections of the lab. Next was to write the function which would poll the user for an input at the button, and then turn on the button while the button remained press.

## GPIO Functionality
The GPIO is set up exactly the same as before. Configure the correct setting to I/O (PxSEL = 0) then the correct orientation for each pin being input and output.

## Polling for input
The way the code polls for an input is by having a continous while loop always be searching for an input from the pin. This is done by doing a bitwise AND with a constant that is equivalent to the bit that contains the connection to the button and stored in a local variable. This is done to ensure that only the value desired (Button input) is being tested. Next the input at the pin with the button is compared in an if statement with a constant that is equivalent to the pin that is connected to the button. If they are equivalent, the LED is turned on.

## Turning on the button
The LED is turned on by setting the value of PxOUT to 1 where the LED is located. The LED is only on when the button is being pushed by having the if statement compared every time the entire code is ran.

## Differences between boards
The biggest difference between these two boards is the location of the buttons and lights. The button on the MSP430G2553is located at P1.3, and the button on the MSP430F5529 is located at P1.1. The LEDs are located at the same location. Another difference is that the buttons on the dev boards appear to have the MSP430G2553 to have a PBNC and the MSP430F5529 to have a PBNO.
