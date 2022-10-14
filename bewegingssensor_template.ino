// Flappy Bird 'bewegingssensor' template
// Gert den Neijsel, Haagse Hogeschool
// Deze code dient om alleen bediening met bewegingssensor te testen.
// Wijzig alleen de code in de functie bepaalPositieMetAccelerometer() en nergens anders!

#include <LSM303AGR_ACC_Sensor.h>

#include <Adafruit_Microbit.h>
Adafruit_Microbit_Matrix display;

#define DEV_I2C Wire1  // Wire1 is voor de interne I2C bus van de Microbit V2
// #define DEV_I2C Wire  // Als je een Microbit V1 hebt, Comment dan de regel hierboven en Uncomment deze.

LSM303AGR_ACC_Sensor Acc(&DEV_I2C);

int bird = 2;  // plek waar de vogel zit. In het midden beginnen.
int vorigeBird = 0;

void bepaalPositieMetAccelerometer(int&);  // forward declaration, zie https://en.wikipedia.org/wiki/Forward_declaration

void setup() {
  DEV_I2C.begin();  // i2c aanzetten
  Acc.begin();      // accerometer aanzetten
  Acc.Enable();     // accerometer starten
  display.begin();  // matrix display aanzetten
}

void loop() {
  bepaalPositieMetAccelerometer(bird);
  if (bird != vorigeBird) {
    display.drawPixel(0, vorigeBird, LED_OFF);
  } else {
    display.drawPixel(0, bird, LED_ON);
  }
  vorigeBird = bird;
  delay(20);
}

void bepaalPositieMetAccelerometer(int& vogel) {
  // Read accelerometer LSM303AGR.
  int32_t accelerometer[3];
  Acc.GetAxes(accelerometer);

  // "Waterpas" demo;
  // accelerometer[0] en accelerometer[1] geven int waardes grofweg tussen -1000 en +1000,
  // We vertalen dit met de map() functie naar een waarde van 0 t/m 4 (led-coördinaten).
  // Als je uitleg wilt van de Arduino map() functie klik dan met de muis op het woord 'map' en druk Ctrl+Shift+F
  // Door het getal 'limiet' te verkleinen, vergroot je de gevoeligheid (hoef je minder schuin te houden).

  vogel = map(1,1,1,1,1); // Hier gebeurt alle magie. Wijzig deze regel en kijk wat verder nodig is.
}