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

void show_temp() {
  ths.requestTemperatures();
  Serial.print("THS, ");
  Serial.print(ths.getTempCByIndex(0));
}

void show_press() {
  int p;
  p = analogRead(ANLG0);
  Serial.print("ANLG0, ");
  Serial.print(p);
}

void show_gsr() {
  int gsr_value = analogRead(GSR);
  int last_three_digits = gsr_value % 1000;  // Extract the last three digits
  Serial.print(", GSR, ");
  Serial.print(last_three_digits);  // Print only the last three digits
}

void loop() {
  show_temp();
  Serial.print(", ");
  show_press();
  Serial.print(", ");
  show_gsr();
  Serial.println("");
  delay(100);  // 次のデータ取得まで100ミリ秒待機
}
