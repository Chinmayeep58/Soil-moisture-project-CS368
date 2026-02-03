// #define SOIL_PIN 34
// #define RELAY_PIN 26

// void setup() {
//   Serial.begin(115200);
//   pinMode(RELAY_PIN, OUTPUT);
//   digitalWrite(RELAY_PIN, LOW); // Relay OFF initially
// }

// void loop() {
//   int soilValue = analogRead(SOIL_PIN); // 0–4095

//   Serial.print("Soil Moisture: ");
//   Serial.println(soilValue);

//   // Dry soil → Relay ON
//   if (soilValue < 2000) {
//     digitalWrite(RELAY_PIN, HIGH);
//   } 
//   // Wet soil → Relay OFF
//   else {
//     digitalWrite(RELAY_PIN, LOW);
//   }

//   delay(1000);
// }



#define SOIL_PIN 34

void setup() {
  Serial.begin(115200);
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);

  // Label: 1 = Dry, 0 = Wet
  int label = (soilValue < 2000) ? 1 : 0;

  // CSV format
  Serial.print(millis());
  Serial.print(",");
  Serial.print(soilValue);
  Serial.print(",");
  Serial.println(label);

  delay(1000);
}
