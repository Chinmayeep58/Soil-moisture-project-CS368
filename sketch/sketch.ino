#define SOIL_PIN 34 // ADC pin

// Calibration values
#define DRY_THRESHOLD 2000  
#define SENSOR_WET 1200
#define SENSOR_DRY 2600

void setup() {
  Serial.begin(115200);
  delay(1000);

  // CSV header
  Serial.println("time_ms,soil_value,moisture_percent,label");
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);

  // Convert sensor value to moisture percentage
  float moisturePercent = (SENSOR_DRY - soilValue) / float(SENSOR_DRY - SENSOR_WET) * 100;
  if(moisturePercent < 0) moisturePercent = 0;
  if(moisturePercent > 100) moisturePercent = 100;

  // Labeling logic
  // 1 = DRY (irrigation needed)
  // 0 = WET (no irrigation)
  int label = (soilValue > DRY_THRESHOLD) ? 1 : 0;  // keep your logic (higher value = dry)

  // CSV output
  Serial.print(millis());
  Serial.print(",");
  Serial.print(soilValue);
  Serial.print(",");
  Serial.print(moisturePercent);
  Serial.print(",");
  Serial.println(label);

  delay(1000);  // 1 sample per second
}