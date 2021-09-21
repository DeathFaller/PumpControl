#include "UpDownButton.h"

UpDownButton::UpDownButton(
	int const &pin,
	int const &init_value
	)
: Button(pin)
{
	value = init_value;
}

int UpDownButton::check()
{
	if (pressed())
	{
		return value;
	}
	else
	{
		return 0;
	}
}
