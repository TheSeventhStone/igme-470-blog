// C++ code
//
int npnPin = A0;
int npnState = 0;
int digPinVal = 3;
int ledBase = 255;
float decayBase = -8;
float chargeBase = 6;

void setup()
{
  pinMode(digPinVal, OUTPUT);
  pinMode(npnPin, INPUT);
}

void loop()
{
  npnState = digitalRead(npnPin);
  //if ring activated
  if(npnState == HIGH)
  {
    analogWrite(digPinVal, ledBase);
    ledBase +=decayBase;
    if(ledBase < 0) {ledBase = 0;}
  }
  //if ring deactivated
  else
  {
    analogWrite(digPinVal,0);
    if(ledBase < 255)
    {
      ledBase+=chargeBase;
    }
    if(ledBase > 255) {ledBase = 255;}
    
  }
        
  delay(150);
}