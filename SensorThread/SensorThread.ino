#include "Thread.h"
#include "ThreadController.h"
#include <TimerOne.h>

// Create a new Class, called SensorThread, that inherits from Thread
class SensorThread: public Thread
{
public:
	int value;
	int pin;
	void run(){
		// Reads the analog pin, and saves it localy
		value = map(analogRead(pin), 0,1023,0,255);
		runned();
	}
};

// Now, let's use our new class of Thread
SensorThread analog1 = SensorThread();
SensorThread analog2 = SensorThread();

// Instantiate a new ThreadController
ThreadController controller = ThreadController();

// This is the callback for the Timer
void timerCallback(){
	controller.run();
}

void setup(){

	Serial.begin(9600);

	// Configures Thread analog1
	analog1.pin = A1;
	analog1.setInterval(100);

	// Configures Thread analog2
	analog2.pin = A2;
	analog2.setInterval(100);

	// Add the Threads to our ThreadController
	controller.add(&analog1);
	controller.add(&analog2);
 
	Timer1.initialize(20000);
	Timer1.attachInterrupt(timerCallback);
	Timer1.start();

}

void loop(){
	// Do complex-crazy-timeconsuming-tasks here
	delay(1000);
	
	// Get the fresh readings
	Serial.print("Analog1 Thread: ");
	Serial.println(analog1.value);

	Serial.print("Analog2 Thread: ");
	Serial.println(analog2.value);

	// Do more complex-crazy-timeconsuming-tasks here
	delay(1000);

}

