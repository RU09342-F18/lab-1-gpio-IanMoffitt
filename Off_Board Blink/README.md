## Reset Circuitry
After reading over the data sheet and doing extensive research online, I found that the reset circuit should be set like a lowpass filter with a resistor value of 47k Ohms and a capacitor with a value of 1nF. Considering I was sick during the second lab period it was tough to find the capacitor, but it turns out that I had a electronics kit at home and had a capacitor labeled 102, this capacitor is equivalent to 1nF. Setting the filter up is shown in the picture provided.

## Power Supply
The power supply of the board is another important aspect of using the processor out of the dev board. The board operates on 5V, which is supplied by the dev board. VSS is GND which is also produced by the board.

## LED Circuitry
The voltage delivered out of any port is approximately 3.4V, so I needed to decide a safe voltage to be delivered out of the output to the LED. I looked up the safe current to pass through a Green and Red diode which is approximately 16-18mA. Knowing that a diode drops a constant voltage of 0.7V, I tried to figure out what resistor would be necessary to pass the recommended current of 17mA. Using Ohms law I deduced that the resistance should be about 268 Ohms, connecting the proper resistors in series produces this resistance.

# Off Board Blink
Now that we have the whole blinking LED out of the way, why don't we try making things a little more convenient by taking the G2553 off the development board and into a breadboard. In addition to the software, your README needs to also contain a picture of your circuit with at least 2 LEDs blinking all on a breadboard and without a development board. This means that you will need:
* Proper power being supplied to the processor
* Proper Reset Circuitry
* Proper Bypass and Bulk Capacitors as needed

Please be advised that you can easily damage or destroy one of the pins on the MSP430 by applying the wrong voltage or attempting to draw too much current from it. Really check your design before you power up to ensure you do not need request another processor.

## "Do I need to use a power supply to power this thing?"
In the beginning part of the exercise, I would say that you can use the 5V/3.3V rails built into the development board by running wires. However, I would recommend looking into how to supply the processor from something like a battery or the power supply. You might want to look into different types of regulators. For example, your circuits may be powered off of a battery that is only 1.8V, or on a system that can only supply you with 13V.

## "What about the buttons and resistors and LEDS?"
You remember those parts bins in the back of the teaching labs? They contain most everything you will need to do this portion of the lab. You should really make a effort to try and replicate what is on those development boards on the breadboard so you can begin to see what is needed to design with a microcontroller. Mess around with different color LEDS and see if they behave the same as the simple Red LEDs.

# YOU NEED TO CREATE THE FOLLOWING FOLDER
* MSP430G2553

## Extra Work
Once you get to this point, you are pretty much set in terms of GPIO mastery getting the LEDs to blink, but there are some more exploratory tasks that you can do.

### Off-Board Programming
Do we need to keep re-inserting the MSP into the development board to program it, or is there some way to keep the chip in the circuit? For starters, try to connect the header which connects the debugger and emulator (that parts that is really dense in parts) to your chip on your board. You will need to look at the datasheets for the MSP430G2553 and the Launchpad itself to see where and how to connect to the programmer. Next, you should really look at using the JTAG connector that is also available on your board.

### UART/Button Control
Remember that stuff you did a few parts ago? Can you actually get all of that working again off of the development board? Can you control which lights are on, the speed they blink at, etc.
