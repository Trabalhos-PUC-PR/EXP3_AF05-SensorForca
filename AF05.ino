#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define LED_COUNT 20

int analogMap;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
	Serial.begin(9600);
  	pinMode(A0, INPUT);
}

void loop(){
  int analogMap = map(analogRead(A0), 0, 914, 0, 20);
  colorWipe(analogMap);
}

void colorWipe(int analogMap) {
      	Serial.println(analogMap);
  for(int i=0; i<strip.numPixels(); i++) {
    if(i < analogMap){
    	strip.setPixelColor(i, strip.Color(255, 0, 0)); 
    }else{
    	strip.setPixelColor(i, strip.Color(0, 0, 0)); 
    }
  }
   	strip.show();              
}