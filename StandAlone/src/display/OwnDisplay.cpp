 #include "OwnDisplay.h"
 
 OwnDisplay::OwnDisplay()
 {
	 oled = new SSD1306AsciiWire();
	 oled->begin(&Adafruit128x64, DISPLAY_ADDRESS);
	 
	 oled->setFont(Adafruit5x7);
	 
	 oled->clear();
	 oled->println("Init ...");
	 delay(1000);
 }
 
void OwnDisplay::showMsg(char *msg, size_t len)
{
	clearDisplay();
	for (size_t i = 0; i < len; ++i)
	{
		oled->print(msg[i]);
	}
	oled->println();
}

void OwnDisplay::showMsg(char *msg, size_t len, float const &code)
{
	showMsg(msg, len);
	oled->println(String(code));
}

void OwnDisplay::showMsg(char *msg, size_t len, float const &actual, int const &max)
{
	showMsg(msg, len, actual);
	oled->println("of");
	oled->println(String(max));
}

void OwnDisplay::showMsg(char *msg, size_t len, int const &code)
{
	showMsg(msg, len);
	oled->println(String(code));
}

void OwnDisplay::showMsg(char *msg, size_t len, int const &actual, int const &max)
{
	showMsg(msg, len, actual);
	oled->println("of");
	oled->println(String(max));
}

void OwnDisplay::showMsg(char *msg, size_t len, uint32_t const &code)
{
	showMsg(msg, len);
	oled->println(String(code));
}

void OwnDisplay::showMsg(char *msg, size_t len, uint32_t const &actual, int const &max)
{
	showMsg(msg, len, actual);
	oled->println("of");
	oled->println(String(max));
}

void OwnDisplay::showDebugCode(int const &code, bool const &wait)
{
	clearDisplay();
	oled->print("Debug: ");
	oled->println(String(code));
	if (wait)
	{
		delay(1000);
	}
} 

 void OwnDisplay::clearDisplay()
 {
	 oled->clear();
	 // Present, if the Adafruit SSD1306 Lib should be used. 
	 // Cursor must be positioned after clear!
 }
