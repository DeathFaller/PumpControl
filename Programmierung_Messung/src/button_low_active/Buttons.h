#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

class Button
{
	public:
		Button(int const &);
		~Button() = default;
		
		bool pressed();
		int pinPressed();
	
	private:
		int pin;
		uint32_t timeOfLastCheck;
		bool lastState;
		bool state;
};

#endif 
