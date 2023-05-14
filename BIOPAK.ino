/////////////////////////////////////////////////////////

#include "Arduino.h" 

#define LedPin 3
byte bV;// button value
byte gMode = 0;
byte oV = 0; // old mode
int ledRound = 0;

#define MAX_MODES 4
#define LED_QTY 2
#define LED_PIN_START 5
#define LIGHTS_SENSOR_PIN A2
#define POTEN_PIN A0
#define BUTTON_PIN 7
void setup() {
    pinMode(LedPin, OUTPUT);
    pinMode(BUTTON_PIN,INPUT);
    pinMode(LIGHTS_SENSOR_PIN, INPUT);
    pinMode(POTEN_PIN, INPUT);
    for(byte i = 0; i < LED_QTY; i++) {
      pinMode(LED_PIN_START + i, OUTPUT); 
      
    }
    Serial.begin(9600); 
    digitalWrite(LedPin, LOW);               
}

byte changeMode(byte mode = 0){
  oV =  bV;
  bV=digitalRead(BUTTON_PIN);// read the level value of pin 7 and assign if to val
  //Serial.println(bV);
  //Serial.println(999); 
  delay(10); 
  if((bV ==  0)&&(oV == 1)){
    mode++;
    if(mode >= MAX_MODES){
      mode = 0;
    }
    delay(100); // czeka
    Serial.println(mode);
  } 
  return mode;
}
void mode3LightsOn(byte mode) {
  digitalWrite(LedPin, HIGH);  
}
void mode1AdjustableLights(byte mode) {
  int ledRoundOld = ledRound;
  int val=analogRead(POTEN_PIN);// read the analog value from the sensor and assign it to val
  val = val / 3.89;                      
   analogWrite(LedPin, val);
  //ledRound = round((val/10.0)*2.55);
  //ledRound = round((ledRound + ledRoundOld*7)/8);
  //ledRound = ledRound > 250 ? 255 : ledRound;

  Serial.println(ledRound);// display value of val
}
void mode2LightSensorLights(byte mode) {
  int sensorValue = analogRead(LIGHTS_SENSOR_PIN);
  if (sensorValue < 50) {
      //digitalWrite (LIGHTS_PIN, LOW);
      analogWrite(LedPin, LOW);   
  }
  else  {
      //digitalWrite (LIGHTS_PIN, HIGH);
        analogWrite(LedPin, HIGH);
  }
 // Serial.println(digitalRead(LIGHTS_SENSOR_PIN)); 
}
void mode0LightsOff(byte mode) {
  //digitalWrite(LIGHTS_PIN, LOW);
  digitalWrite(LedPin, LOW);             
}
void loop()   {
  for(byte i = 0; i < LED_QTY; i++) {
    byte sdv = gMode >> i;
    bool zeroBite = sdv & 1;
    if(zeroBite) {
      digitalWrite(LED_PIN_START + i, HIGH); 
    } else {
      digitalWrite(LED_PIN_START + i, LOW);
    }
  }
  gMode = changeMode(gMode);
  //Serial.println(gMode);
  switch (gMode) {
    case 3:
      mode3LightsOn(gMode);
    break;
    case 1:
      mode1AdjustableLights(gMode);
    break;
    case 2:
      mode2LightSensorLights(gMode);
    break;
    case 0:
      mode0LightsOff(gMode);
    break;
   

  }
}

  
//////////////////////////////
