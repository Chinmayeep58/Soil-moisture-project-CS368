#define SOIL_PIN 34
#define RELAY_PIN 26

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relay OFF initially
}

void loop() {
  int soilValue = analogRead(SOIL_PIN); // 0–4095

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  // Dry soil → Relay ON
  if (soilValue < 2000) {
    digitalWrite(RELAY_PIN, HIGH);
  } 
  // Wet soil → Relay OFF
  else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(1000);
}
