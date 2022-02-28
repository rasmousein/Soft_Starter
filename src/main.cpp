#include <Arduino.h>

#define zerocross 2 // pin for the external interrupt (Input with Pullup)
#define triac 3     // pin to trigger the Triac (Output)
#define ledred 4    // LED shows whether system is ready to softstart
#define ledgreen 5  // LED  shows whether softstart occured
#define push 6      // Push Button Input to start the softstart
bool zero = 0;      // variable as a status flag which shows whether a zero crossing point occured

uint8_t powerLevel = 0;

void setup()
{
  pinMode(zerocross, INPUT_PULLUP);
  pinMode(triac, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(push, INPUT_PULLUP);
  digitalWrite(triac, LOW);
  digitalWrite(ledred, HIGH);
  digitalWrite(ledgreen, LOW);
  Serial.begin(115200);
//  TCCR2B = TCCR2B & B11111000 | B00000111; // for PWM frequency of 30.64 Hz
//  TCCR2B = TCCR2B & B11111000 | B00000110; // for PWM frequency of 122.55 Hz
//  TCCR2B = TCCR2B & B11111000 | B00000101; // for PWM frequency of 245.10 Hz
}

void loop()
{
    digitalWrite(triac, HIGH);
    delay(5);
    digitalWrite(triac, LOW);
    delay(5);
}