# Multiple Blink Read ME
This code blinks two LEDs at two seperate frequencies. The periods chosen are 1 second for LED 1 and half a second for LED 2. The biggest concept necessary to understand what is happening is to imagine the lights blinking as a xy plane with two sine waves on it, each LED corresponds to one sine wave. Whenever the sine wave is positive, the LED is on, whenever the LED is negative, the LED is off. I chose to have the one light blink twice as fast as that made the code only need to oscillate itself for the period of the second LED.

## GPIO Function
The steps to set the Ports to GPIO function are the same as in Simple Blink. Set the PxSEL register to hold 0 in the pins used, and set the PxDIR to 1 for output (Px is the port X).

## Frequency
The lights toggle at 2 different frequencies by having both of the lights eventually turn on/off at the exact same instance. This means that it has a repetitive pattern and can be coded as a loop to repeat that pattern. For the pattern to be true it needs to have a consistent initial state so the first step is to set the initial values of the LEDs to off. After that the loop can begin, so the first line of code in there is to toggle the LEDs (ON/ON). After a delay of 1/4 second the value of the second LED is toggled (ON/OFF). After another quarter second it has been the full half second, meaning the second LED should have completed a full cycle and the first LED has completed half a cycle so both toggle at the same time again (OFF/ON), the loop repeats. The next cycle once again delays by a 1/4 second and then toggles the second LED (OFF/OFF). After that the cycle repeats after a 1/4 second delay where the initial condition is reached again when both LEDs are toggled (ON/ON).

## Differences between boards
The only difference between the two boards is that the second LED is connected to a different port and pin. On the MSP430G2553 the second LED is on Port 1 Pin 6, but on the MSP430F5529 it is on Port 4 Pin 7. This changes the bit math that needs to occur to toggle the settings slightly.
