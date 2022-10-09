// Led matrix pinnen voor Microbit V2
const int COL1 = 4;   // Column #1 control // pin 3  bij Microbit V1
const int ROW1 = 21;  // 'row 1' led       // pin 26 bij Microbit V1

void setup() {
  Serial.begin(9600);
  Serial.println("Microbit V2 is ready!");

  // Omdat de LEDs in een matrix staan moet zowel de plus als de min aangestuurd worden.
  // De stroom loopt immers van + naar -
  pinMode(COL1, OUTPUT);  // kolom is de -
  pinMode(ROW1, OUTPUT);  // rij is de +
  digitalWrite(COL1, LOW);
}

void loop() {
  Serial.println("blink!");

  digitalWrite(ROW1, HIGH);
  delay(500);
  digitalWrite(ROW1, LOW);
  delay(500);
}