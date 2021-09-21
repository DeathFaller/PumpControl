#include "DEV_DF_002.h"

DEV_DF_002::DEV_DF_002()
{
	#ifndef DEBUG
		Serial.begin(9600, SERIAL_7O1);
	#else
		Serial.begin(9600);
		Serial.println("DEBUGGING...");
	#endif
	Serial.println("1a");
	Serial.println("aXR");
	delay(5000);
	setValveDirection(1);
}

DEV_DF_002::DEV_DF_002(int const &timeFullStroke)
{
	setTimeForFullStroke(timeFullStroke);
}

void DEV_DF_002::setTimeForFullStroke(int const &timeFullStroke)
{
	Serial.print("AYSS");
	Serial.print(String(timeFullStroke));
	Serial.println("R");
	delay(500);
}

void DEV_DF_002::setValveDirection(int const &dir)
{
	if (dir == 1)
	{
		Serial.println("aOR");
	}
	else
	{
		Serial.println("aIR");
	}
	delay(100);
	direction = dir;
}

int DEV_DF_002::getDirection() const
{
	return direction;
}

bool DEV_DF_002::toAbsPosition (int const &absolutePosition)
{
	bool retValue = false;

	int newPosition = -1;
	#ifdef DEBUG_PUMPING
		Serial.println("{");
		Serial.print("toAbsPosition: ");
		Serial.println(absolutePosition);
	#endif	
	
	switch(checkPosition(absolutePosition))
	{
		case 0:
			newPosition = absolutePosition;
			break;
		case 1:
			newPosition = getTopPosition();
			break;
		case -1:
			newPosition = getBottomPosition();
			break;
			
	}
	Serial.print("aM");
	Serial.print(String(newPosition));
	Serial.println("R");
	delay(100);
	position = newPosition;
	retValue = true;
	
	
	#ifdef DEBUG_PUMPING
		Serial.println("toAbsPosition finished");
		Serial.println("}");
	#endif
	return retValue;
}

bool DEV_DF_002::toRelPosition(int const &relativePosition)
{
	#ifdef DEBUG_PUMPING
		Serial.print("toRelPosition: ");
		Serial.println(relativePosition);
		
	#endif 
	return toAbsPosition(position - relativePosition);
}

int DEV_DF_002::checkPosition(int const &pos)
{
	#ifdef DEBUG_PUMPING
		Serial.println("###");
		Serial.println("checkPosition: ");
		Serial.print("act. Pos: ");
		Serial.println(position);
		Serial.print("new Pos: ");
		Serial.println(pos);
	#endif
	int retValue = 0;
	
	if (pos > getBottomPosition())
	{
		retValue = -1;
		#ifdef DEBUG_PUMPING
			Serial.print("retValue: ");
			Serial.println(retValue);
			Serial.println("###");
		#endif
	}
	else 
	{
		if (pos < getTopPosition())
		{
			retValue = 1;
			#ifdef DEBUG_PUMPING
				Serial.print("retValue: ");
				Serial.println(retValue);
				Serial.println("###");
			#endif
		}
	}
	#ifdef DEBUG_PUMPING
		Serial.print("retValue: ");
		Serial.println(retValue);
		Serial.println("###");
	#endif
	return retValue;
}


void DEV_DF_002::fillPump(int const &promille)
{
	#ifdef DEBUG_PUMPING
		Serial.println("###");
		Serial.print("Fill pump: ");
		Serial.println(promille);
	#endif
	
	int diffBottomTop = getBottomPosition() - getTopPosition();
	
	#ifdef DEBUG_PUMPING
		Serial.println("difference bottom - top");
		Serial.println(diffBottomTop);
	#endif
	
	float factor = (float)promille / 1000.0;
	
	#ifdef DEBUG_PUMPING
		Serial.print("factor: ");
		Serial.println(factor);
	#endif
	
	double newRelPos = factor * diffBottomTop;
	
	#ifdef DEBUG_PUMPING
		Serial.print("newRelPos: ");
		Serial.println(newRelPos);
	#endif
	
	
	
	toRelPosition((int)newRelPos);	
	
	#ifdef DEBUG_PUMPING
		Serial.println("###");
	#endif
}


float DEV_DF_002::getFilling() const
{
	return (position / (getBottomPosition() - getTopPosition())*10);
}


int DEV_DF_002::getBottomPosition() const
{
	#ifdef DEBUG_CONSTANTS
		Serial.print("Bottom Position: ");
		Serial.println(DEV_DF_002_MaxPosition);
	#endif
	return DEV_DF_002_MaxPosition;
}

int DEV_DF_002::getTopPosition() const
{
	#ifdef DEBUG_CONSTANTS
		Serial.print("Top Position: ");
		Serial.println(DEV_DF_002_MinPosition);
	#endif
	return DEV_DF_002_MinPosition;
}



// To be implemented later	
	
void DEV_DF_002::sendCommand(String const &)
{
	
}

void DEV_DF_002::waitForAck()
{
	
}