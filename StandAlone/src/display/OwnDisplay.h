#ifndef OWNDISPLAY_H
#define OWNDISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define DISPLAY_ADDRESS 0x3C

#define OLED_RESET -1

namespace ownDisplay
{
	const char MSG_STEPSIZE[] = "Ventil \n Schrittweite: ";
	const char MSG_PUMPING[] = "Up";
	
}

class OwnDisplay
{
	public:
		OwnDisplay(); // Constructor
		~OwnDisplay() = default;
		
		void showErrorCode(int const &);
		void showDebugCode(int const &, bool const & = true);
		
		void showMsg(char *, size_t);
		
		// TODO: Use function template!
		
		void showMsg(char *, size_t, float const &);
		void showMsg(char *, size_t, float const &, int const&);
		void showMsg(char *, size_t, int const &);
		void showMsg(char *, size_t, int const &, int const&);
		void showMsg(char *, size_t, uint32_t const &);
		void showMsg(char *, size_t, uint32_t const &, int const&);
		
		void showSetPressure(int const &);
		void showNumberOfMeasurements(int const &);
		void showRupturePressure(int const &);
		void showMeasurementTime(int const &);
		void showFinishMessage();
		void showMessageFlowControl(float const &);
		void showMessageWash();

		
		void showMessageFlowControl_Fill();
		void showMessageFlowControl_Empty();
		
		void showMessageMeasuring(int const &, int const &);
	
	private:
		SSD1306AsciiWire *oled;
		void clearDisplay();
};
#endif
