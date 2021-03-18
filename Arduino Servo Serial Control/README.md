This is my code for controller servos from a Raspberry Pi via an Arduino Uno.

I originally tried to connect the servos directly to my Raspberry Pi, but found that the servo movements were quite jittery and they wouldn't stay still when they reached the position they were moving to unless i powered off the servo.

When i ran similar code on my Arduino Uno, the servo movement was smooth and it remained nicely in position when it finished it's movement.

After discovering this, i decide that it would be best to control the servos from the Arduino and use the Pi to send 'angles' to the Arduino to forward on to the servos via a serial connection.
For this to work, the Arduino needs to be connect to the Raspberry Pi either by USB, or via the GPIO ports (I chose to use USB, as this is the far easier option!)

I wrote the sketch for the Arduino and upload it and then wrote a 'test script' to run on the Pi to check that the Arduino would respond to commands.
The test script initially sets the servos to a 90 degree angle before going back to 0 degrees and then increasing 10 degrees at a time all the way up to 180 (my servo's maximum angle)

----

In this folder you will find 2 more folders - Arduino and Raspberry Pi.
It should be fairly self explanitory, but the code in the 'Arduino' folder is the sketch i upload to the Arduino, and the code in the 'Raspberry Pi' folder is the code i used to test that everything was working correctly.