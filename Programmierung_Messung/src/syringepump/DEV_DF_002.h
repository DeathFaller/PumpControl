#ifndef PUMP_DEV_DF_002
#define PUMP_DEV_DF_002

//#define DEBUG
//#define DEBUG_ALL
//#define DEBUG_PUMPING

#ifdef DEBUG_ALL
	#define DEBUG
	#define DEBUG_CONSTANTS
	#define DEBUG_PUMPING
#endif

#include <Arduino.h>
#include "Pump.h"

const int DEV_DF_002_MaxPosition = 1000;
const int DEV_DF_002_MinPosition = 0;


class DEV_DF_002: public Pump
{
	public:
		DEV_DF_002();
		DEV_DF_002(int const &);
		
		~DEV_DF_002() = default;
		
		// To be tested:
		
		void setValveDirection(int const & = 1);
		void fillPump(int const & = 1000);		// Angabe in Promille

		int getDirection() const; // rly int?
		float getFilling() const;		// sinnvoll? Als Prozentangabe
		
		// Done
		
	private:
		int direction = 0;
		int position = 0;
		
		void setTimeForFullStroke(int const &);
		
		// To be tested:
		
		// To be implemented
		int getTopPosition() const;
		int getBottomPosition() const;
		
		bool toAbsPosition(int const &);
		bool toRelPosition(int const &); // Positiver Wert -> Entleeren
		
		int checkPosition(int const &);	
		void sendCommand(String const &);
		void sendCommand(String const &, int const &);
		void waitForAck();
		
		// Done
		
	
	
};


#endif