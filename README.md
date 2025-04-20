## Arduino_Kitchen_LED-counter-controller

This simple bit of arduino C code just monitors a simple analog light sensor 
module (read through analogRead()), to give a simple 0-1023 light value. If
the ambient light value exceedes a preprogammed level, then it turns on a
power relay, which powers my under-counter LED light strips (12v).

The design points the CdS light sensor at the main kitchen ceiling light so
that when that light is turned on, the counter lights light up.  The light up
threshold that works best for me seems to be around 500.  The sensor is rather
noisy, so we take 10 readings over 20mS and average them.

Since the CdS photo-resistor is in series with a low value voltage divider
resistor, it doesn't quite get down to 0, but also rarely goes over 900 for
ambient room light. You will need to ajust the threshold light value to meet
your daytime/nighttime room levels.

The code is super simple, is NOT reentrant, and operates on global variables. 
You have been warned. hehe ;)




