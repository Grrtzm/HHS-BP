// Flappy Bird 'knoppen' template
// Gert den Neijsel, Haagse Hogeschool
// Deze code dient om alleen de knoppen afhandeling te testen.
// Wijzig alleen de code in de functie bepaalPositieMetKnoppen() en nergens anders!

#include <Adafruit_Microbit.h>
Adafruit_Microbit_Matrix display;

int bird = 2;  // plek waar de vogel zit. In het midden beginnen.
int vorigeBird = 0;

void bepaalPositieMetKnoppen(int&);  // forward declaration, zie https://en.wikipedia.org/wiki/Forward_declaration

void setup() {
  display.begin();  // matrix display aanzetten
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
}

void loop() {
  bepaalPositieMetKnoppen(bird);
  if (bird != vorigeBird) {
    display.drawPixel(0, vorigeBird, LED_OFF);
  } else {
    display.drawPixel(0, bird, LED_ON);
  }
  vorigeBird = bird;
  delay(20);
}

void bepaalPositieMetKnoppen(int& vogel) {
  // Het resultaat van deze functie is dat de variabele vogel
  // door op de knoppen te drukken
  // een waarde krijgt in het bereik 1 .. 5 (er zijn 5 leds)
  // Voor inspiratie zie ingebouwde voorbeelden Buttons, Debounce en StateChangeDetection
  // Let op: je hoeft in deze code NIET voor debounce te zorgen. Dat gebeurt al in loop().

  // Vervang dit door je eigen code:
  vogel = 2;  // Variabele een waarde geven, anders is deze ongedefinieerd.
}