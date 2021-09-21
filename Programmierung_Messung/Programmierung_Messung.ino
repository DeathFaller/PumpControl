#include "src\button_low_active\Buttons.h"
#include "src\syringepump\DEV_DF_002.h"

Pump *pump = nullptr;

Button *up = nullptr;
Button *down = nullptr;
Button *meas = nullptr; 


const int measButtonPin = 5;
const int downButtonPin = 2;
const int upButtonPin =3;


int checkButtons()
{
	int retValue = -1;
	retValue = up->pinPressed();	// Muss das hier überhaupt nach jeder Abfrage returned werden?
	if (retValue != - 1)
	{
		return retValue;
	}
	retValue = down->pinPressed();
	if (retValue != - 1)
	{
		return retValue;
	}
	retValue = meas->pinPressed();
	if (retValue != - 1)
	{
		return retValue;
	}
	return retValue;
		
}


void setup() {
	pump = new DEV_DF_002();

	down = new Button(downButtonPin);
	up = new Button(upButtonPin);
	meas = new Button(measButtonPin);
}



void loop() {
	// put your main code here, to run repeatedly:
	switch(checkButtons())
	{
		case downButtonPin:		// Unterster Knopf gedrückt
			pump->setValveDirection(1);
			pump->fillPump(-1000);
			break;
		case measButtonPin:		// Mittlerer Knopf gedrückt
			pump->setValveDirection(1);
			pump->fillPump(1);
			break;
		case upButtonPin: 		// Oberster Knopf gedrückt
			pump->setValveDirection(-1);
			pump->fillPump();
			break;

		default:			// No Button pressed
			delay(5);
			break;
	}
	delay(5);

}
