#include "Buttons.h"

Button::Button(int const &init_pin)
:
pin(init_pin)
{
	pinMode(pin, INPUT_PULLUP);
	lastState = digitalRead(pin);
	state = digitalRead(pin);
}

bool Button::pressed()
{
	bool pressed = false;
	while (digitalRead(pin) == LOW)
	{
		pressed = true;
		delay(10);
	}
	return pressed;
}

int Button::pinPressed()
{
	int pressed = -1;
	while (digitalRead(pin) == LOW)
	{
		pressed = pin;
		delay(10);
	}
	return pressed;
}