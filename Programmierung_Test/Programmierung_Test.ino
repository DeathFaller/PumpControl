
int pumpPos = 0;

void valveChamber()
{
  Serial.println("aOR");
  delay(1000);
}
void valveMeasCont()
{
  Serial.println("aIR");
  delay(1000);
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  
  // put your setup code here, to run once:
  Serial.begin(9600, SERIAL_7O1);
  Serial.println("1a");
  delay(2000);
  Serial.println("aXR");
  delay(5000);
  Serial.print("aYSS");
  delay(100);
  Serial.print(String(6));
  Serial.println("R");
  delay(100);
  valveChamber();
  Serial.println("aM0R");
  delay(10000);
}

bool buttonPressed()
{
  bool pressed = false;
  while (digitalRead(2) == LOW)
  {
    pressed = true;
    delay(10);
  }
  return pressed;
}

void loop() {
  while (!buttonPressed())
  {
    delay(5);
  }
  if (pumpPos < 200){
    valveChamber();
    movePump(1000 - pumpPos);
    delay(10000);
    valveMeasCont();
  }
  else
  {
    movePump(-1);
  }
}

void movePump(int howFar)
{
  pumpPos += howFar;
  Serial.print("aM");
  Serial.print(String(pumpPos));
  Serial.println("R");
  delay(100);
}
