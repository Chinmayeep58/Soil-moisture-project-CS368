// #define SOIL_PIN 34

// void setup() {
//   Serial.begin(115200);
// }

// void loop() {
//   int value = analogRead(SOIL_PIN);
//   Serial.println(value);
//   delay(1000);
// }



#define SOIL_PIN A0   // Analog pin

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Soil Moisture Calibration Mode (Arduino)");
  Serial.println("Place sensor in soil and observe values");
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);  // 0–1023
  Serial.println(soilValue);
  delay(1000);
}
