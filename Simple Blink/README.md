# Simple Blink ReadMe
This program has two main functions. The first chunk of code is to have Port1 function as a GPIO and designate it as an output. After Port1 is set as a GPIO there is a while loop which constantly toggles the status of the light after a set delay.

## Set GPIO Function
The GPIO is set in 2 stages. The first step is to set the ports "PSEL" Register to 0 which sets the port to work as an I/O port. After that the direction of data needs to be set to output so electricity is delivered to the LED. This is done setting the direction register to hold a value of 1 at the bit that controls the LED.

## Toggle Light
The light is toggled in 2 stages. The first stage is to clear the value of the register Port 1 Out and set the LED to be off. After that is done the code enters a never ending while loop which has a delay of a half a second, then toggles the light using a bitwise exclusive OR. After that code runs the loop runs again.
