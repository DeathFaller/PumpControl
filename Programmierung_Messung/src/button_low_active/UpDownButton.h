#ifndef UPDOWNBUTTON_H
#define UPDOWNBUTTON_H

#include <Arduino.h>
#include "Buttons.h"

const int value_UpButton = 1;
const int value_DownButton = -1;

class UpDownButton : public Button
{
	public:
		UpDownButton(int const &, int const &);
		~UpDownButton() = default;
		int check();
		
	private:
		int value;
};

#endif
