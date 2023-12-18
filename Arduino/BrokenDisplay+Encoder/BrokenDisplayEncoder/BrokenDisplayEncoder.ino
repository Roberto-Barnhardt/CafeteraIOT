/*
Hecho:
  - Rotary encoder contando correctamente.
Por hacer:
  - MQTT...
  - OLED...
  - MENU ENTERO...
*/
//----------------------------------------------------------------------------------
// ENCODER SETUP
//----------------------------------------------------------------------------------
// Libraries
#include <ESP32Encoder.h> 

// Definitions
#define encA 17 
#define encB 16 
long newPosition = 0;
long lastPos = 0;
//bool stuffChanged = false;
ESP32Encoder encoder;

// Functions
/*
void doEncoder() {
  newPosition = encoder.getCount() / 2;
  if (newPosition != lastPos) {
    lastPos = newPosition;
    stuffChanged = true;
  }
}
*/
//----------------------------------------------------------------------------------
// SETUP
//----------------------------------------------------------------------------------
void setup() {
  // Serial
  Serial.begin(115200);
  
  // Encoder
  encoder.attachHalfQuad(encB, encA);
  encoder.setCount(0);  


}

//----------------------------------------------------------------------------------
// LOOP
//----------------------------------------------------------------------------------
void loop() {
  // Encoder  

  newPosition = encoder.getCount() / 2;
  if (newPosition != lastPos) {
    lastPos = newPosition;
    Serial.println()
  }
}
