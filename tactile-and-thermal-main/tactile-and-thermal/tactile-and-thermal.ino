#include <OneWire.h>
#include <DallasTemperature.h>

#include "pineapple.h"

const int sensor_bits = 9;
const int sensor_pin = A5;
const int GSR = ANLG1;  // GSRセンサのアナログピン番号をANLG1に設定

OneWire oneWire(sensor_pin);
DallasTemperature ths(&oneWire);

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, HIGH);
  Serial.begin(9600);
  ths.setResolution(sensor_bits);
}

void show_gsr() {
  int sensorValue = 0;
  long sum = 0;
  int gsr_average = 0;
  sensorValue = analogRead(GSR) * 100;
  Serial.println(sensorValue);
}

void loop() {
  show_gsr();
  Serial.println("");
  delay(1000);  // 次のデータ取得まで100ミリ秒待機
}
