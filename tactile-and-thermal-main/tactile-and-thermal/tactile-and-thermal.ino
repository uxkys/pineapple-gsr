#include <OneWire.h>
#include <DallasTemperature.h>
#include "pineapple.h"  // この行は不要な場合は削除

const int sensor_bits = 9;
const int sensor_pin = A5;
const int heartPin = ANLG1;

OneWire oneWire(sensor_pin);
DallasTemperature ths(&oneWire);

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, HIGH);
  Serial.begin(115200);
  ths.setResolution(sensor_bits);
}

void loop() {
  int heartValue = analogRead(heartPin);
  Serial.println(heartValue);
  delay(5);  // 5ミリ秒の遅延
}
