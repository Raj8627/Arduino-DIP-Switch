int dipPins[] = {2, 3, 4, 5};       // DIP Switch Pins
int SwitchAddress;

void setup()
{
 Serial.begin(9600);
 int i;
 for(i = 0; i<=3; i++){
   pinMode(dipPins[i], INPUT);      // set the digital pins (defined above) as input
   digitalWrite(dipPins[i], HIGH);  // set internal pullup resistor on
  }
}

void loop()
{
SwitchAddress = address();
Serial.println(SwitchAddress);
delay(1000);
}
//Read state from DIP Switch (4 positions used)
byte address(){
 int i,j=0;
 
 //Get the switches state
 for(i=0; i<=2; i++){
 j = (j << 1) | digitalRead(dipPins[i]);   // read each input pin
 }
 return j; //return address
}
