#include <Adafruit_Microbit.h>

// Vanaf hier tot setup() zijn allemaal globale variabelen die in elk deel van het programma en in elke functie bruikbaar zijn:
Adafruit_Microbit_Matrix display;

uint8_t matrix[5] = { 0, 0, 0b10000, 0, 0 };  // uint8_t betekent: een unsigned 8 bits integer
bool flap = 1;                                // t.b.v. het knipperen van de vogel
int bird = 2;                                 // positie van vogel vastgezet (handig voor deze opdracht)

void setup() {
  display.begin();  // matrix display aanzetten
}

void loop() {
  // Onderstaande code zit in het spel in void controleerScore()
  if (flap == 1) {  // met het knipperen simuleren we het flapperen
    // Stap 5. Vul de regels hieronder aan met een bitwise operation zodat de meest linker led wordt aangezet.
    matrix[bird] = matrix[bird];  // vogel zit in de meest linker kolom
    flap = 0;
  } else {
    // Stap 6. Vul de regels hieronder aan met een bitwise operation zodat de meest linker led wordt uitgezet.
    // Het is in beide gevallen dezelfde bitwise operation.
    matrix[bird] = matrix[bird];              // de meest linker led uitzetten
    flap = 1;
  }

  display.show(matrix);
  delay(50); // knippersnelheid
  // Stap 7: Kopieer de regels die je zojuist gemaakt hebt naar controleerScore() in het uiteindelijke Flappy Bird spel
}