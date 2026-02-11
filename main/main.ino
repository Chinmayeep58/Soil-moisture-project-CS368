#define SOIL_PIN 34      // ADC pin

// Change this after calibration
#define DRY_THRESHOLD 2000  

void setup() {
  Serial.begin(115200);
  delay(1000);

  // CSV header
  Serial.println("time_ms,soil_moisture,label");
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);

  // Labeling logic
  // 1 = DRY (irrigation needed)
  // 0 = WET (no irrigation)
  int label = (soilValue < DRY_THRESHOLD) ? 1 : 0;

  // CSV output
  Serial.print(millis());
  Serial.print(",");
  Serial.print(soilValue);
  Serial.print(",");
  Serial.println(label);

  delay(1000);  // 1 sample per second
}
