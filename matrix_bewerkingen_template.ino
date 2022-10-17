#include <Adafruit_Microbit.h>
Adafruit_Microbit_Matrix display;

uint8_t matrix[5] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
};
uint8_t gat = 0;  // plek waar het gat in de muur zit.

void setup() {
  randomSeed(analogRead(2));  // pin 2 is niet aangesloten en genereert ruis; basis voor 'random'
  display.begin();            // matrix display aanzetten
}

void loop() {

  display.show(matrix);  // toon de array 'matrix' op het led display

  for (int y = 0; y < 5; y++) {
    // Stap 1
    // Vul de regel hieronder aan met een bitwise operation zodat alle rijen één hele kolom naar links opschuiven.
    matrix[y] = matrix[y];  // vul aan vóór de ;
  }

  uint8_t vorigeGat = gat;
  while (gat == vorigeGat) {  // om te zorgen dat je altijd een gat op een nieuwe locatie hebt.
    gat = random(5);          // de led die uit is in de muur, willekeurig getal 0 .. 4
  }

  for (int y = 0; y < 5; y++) {
    // Stap 2
    // Vul de regel hieronder aan met een bitwise operation zodat alle rijen aan de rechterkant met een 1 gevuld worden.
    matrix[y] = matrix[y];  // meest rechter kolom vullen met 1-en
    if (gat == y) {
      // Stap 3
      // Vul de regel hieronder aan met een bitwise operation zodat in alle rijen het betreffende bitje wordt uitgezet.
      matrix[y] = matrix[y];  // ledje y uitzetten (het gat)
    }
  }

  // Stap 4: Kopieer de regels die je zojuist gemaakt hebt naar het uiteindelijke Flappy Bird spel
  delay(1000);
}