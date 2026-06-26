/*
  Part B: ESP32-Based Prototype
  Temperature and Distance Monitoring with Alert Generation

  Sensors:
  - DHT22 temperature sensor
  - HC-SR04 ultrasonic distance sensor

  Outputs:
  - LED alert
  - Buzzer alert
  - Serial Monitor data logging
*/

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 2
#define BUZZER_PIN 19

const float TEMP_LIMIT = 35.0;     // Alert if temperature exceeds 35 C
const float DIST_LIMIT = 20.0;     // Alert if object is closer than 20 cm

DHT dht(DHTPIN, DHTTYPE);

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = duration * 0.0343 / 2.0;

  return distance;
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("ESP32 Temperature and Distance Monitoring System Started");
  Serial.println("--------------------------------------------------------");
}

void loop() {
  float temperature = dht.readTemperature();
  float distance = readDistanceCM();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (temperature > TEMP_LIMIT || distance < DIST_LIMIT) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("ALERT: Threshold exceeded!");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Status: Normal");
  }

  Serial.println();
  delay(2000);
}
