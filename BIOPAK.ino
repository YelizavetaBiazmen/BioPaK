#include "Arduino.h" 
#include "RGBLed.h" 

//stałe dla LEDa
#define LEDSTRIPRGB_PIN_SIGB  3 
#define LEDSTRIPRGB_PIN_SIGR  9
#define LEDSTRIPRGB_PIN_SIGG  11

#define BUTTON_PIN 13 

#define LedStripRGB_TYPE COMMON_CATHODE

RGBLed LedStripRGB(LEDSTRIPRGB_PIN_SIGR,LEDSTRIPRGB_PIN_SIGG,LEDSTRIPRGB_PIN_SIGB,LedStripRGB_TYPE);
byte bV;// button value
byte gMode = 0;
byte oV = 0; // old mode
int ledRound = 0;

//wpisujemy piny 
#define MAX_MODES 4
#define LED_QTY 2 
#define LED_PIN_START 5 
//#define LIGHTS_PIN 3
//#define SOUND_PIN A0
#define LIGHTS_SENSOR_PIN 12
#define POTEN_PIN 0


//bool statuslamp=false;


void setup() {
    pinMode(BUTTON_PIN,INPUT);// set LED pin as “output”
    //pinMode(SOUND_PIN,INPUT);
    //pinMode(LIGHTS_PIN, OUTPUT);
    pinMode(LIGHTS_SENSOR_PIN, INPUT);

    
    //cykl dla definiowania pinów LEDów, potrzebnych dla numeracji trybów
    for(byte i = 0; i <LED_QTY ; i++) {
      pinMode(LED_PIN_START + i, OUTPUT);
      
    }

    Serial.begin(9600); 
    LedStripRGB.turnOff();   // wyłączamy LED na początek dziłania programy         
}

byte changeMode(byte mode = 0){
  oV =  bV; //wpisujemy znaczenie przecisku, przed tym jak nowe znaczenie zastąpi stare. robimy to dla porównania 
    
  bV=digitalRead(BUTTON_PIN);// read the level value of pin 7 and assign if to val
  Serial.println(bV); 
   

  if((bV ==  LOW)&&(oV == HIGH)){ 
    mode++;
    if(mode >= MAX_MODES){
      mode = 0;
    }
    delay(100);

 

    Serial.println(mode);
  } 
  return mode;
}


void mode3LightsOn(byte mode) {
  LedStripRGB.setRGB(255, 255, 255);  
  //digitalWrite(LIGHTS_PIN, HIGH);
}


void mode1AdjustableLights(byte mode) {

  int ledRoundOld = ledRound; // wpisujemystare znaczenie do innej zmiennej, przed tym, jak ją zastąpi inne znaczenie
  int val=analogRead(POTEN_PIN);// read the analog value from the sensor and assign it to val


  ledRound = round((val/10.0)*2.55); 
  ledRound = round((ledRound + ledRoundOld*7)/8);
  ledRound = ledRound > 250 ? 255 : ledRound;
  Serial.println(ledRound);// display value of val 
  //analogWrite(LIGHTS_PIN,ledRound);
  LedStripRGB.setRGB(ledRound, ledRound, ledRound);
}


void mode2LightSensorLights(byte mode) {
    
    
  if (digitalRead(LIGHTS_SENSOR_PIN) == HIGH) {
      //digitalWrite (LIGHTS_PIN, LOW);
      LedStripRGB.turnOff();   
  }
   else  {
      //digitalWrite (LIGHTS_PIN, HIGH);
        LedStripRGB.setRGB(255, 255, 255);
  }
  Serial.println(digitalRead(LIGHTS_SENSOR_PIN)); 
}



/*void mode3SoundSensorLights(byte mode) {
  
  int value = analogRead(A0);
   Serial.println (value); 
   if(value>30) {
    Serial.println (value);
      statuslamp=!statuslamp; 
      digitalWrite(LIGHTS_PIN,statuslamp);
      delay(50);
   }
}*/


void mode0LightsOff(byte mode) {
  //digitalWrite(LIGHTS_PIN, LOW);
  LedStripRGB.turnOff();             
}
void loop()   { 
  for(byte i = 0; i < 3; i++) {
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
